#include "crypto.hpp"
#include <iostream>

std::string Crack() {
  std::string hash = "ab29d7b5c589e18b52261ecba1d3a7e7cbf212c6";

  std::string salt = "Saltet til Ola";
  int iterations = 2048;

  std::string pass;
  pass.resize(3);

  for(int i = 65; i <= 122; i++) {
    for(int j = 65; j <= 122; j++) {
      for(int k = 65; k <= 122; k++) {

        pass[0] = char(i);
        pass[1] = char(j);
        pass[2] = char(k);

        if(Crypto::hex(Crypto::pbkdf2(pass, salt, iterations, 20)) == hash)
          return pass;
      }
    }
  }
  return "";
}

int main() {
  std::cout << "Password is: " << Crack() << std::endl;
}


// while(Crypto::hex(Crypto::pbkdf2(pass,salt,iterations,20)) != hash && current_pos <= 2){
//char current_char = 65;
//int current_pos = 0;
//     pass[length-current_pos] = current_char;
//   current_char++;
//   if (current_char >=123){
//     current_pos++;
//     current_char=65;
//     length++;
//     pass.resize (length);
//   }
// }
// std::cout << pass << std::endl;
