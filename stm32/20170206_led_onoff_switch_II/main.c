int main(){
  // RCC Base Address = 0x40021000
  // APB2ENR offset = 0x18
  // IOPAEN = 0x4; IOPCEN = 0x10; 
  (*(volatile unsigned*)0x40021018) |= 0x14
  
  // PORTA Base Address = 0x40010800
  // CRL offset = 0x00
  // CNFy = 0x00(push-pull); MODE = 0x01(max, 10MHz)
  (*(volatile unsigned*)0x40010800) = 0x0;
  (*(volatile unsigned*)0x40010800) |= 0x100000;

  // PORTC Base Address = 0x40011000
  // CRH offset = 0x04
  // CNFy = 0x01(Floating Input); MODE = 0x00(Input Mode)
  (*(volatile unsigned*)0x40011004) = 0x0;
  (*(volatile unsigned*)0x40011004) |= 0x400000;
  
  while(1){
     if(((*(volatile unsigned*)0x40011008) & 0x2000) == 0){
      // PORTA Base Address = 0x40010800
      // BSRR offset = 0x10
      // Set = 0x20; Reset = 0x200000
      // (*(volatile unsigned*)0x40010810) |= 0x20;
       
      // PORTA Base Address = 0x40010800
      // ODR offset = 0x10
      // Set = 0x20; Reset = 0x200000
      // (*(volatile unsigned*)0x40010810) |= 0x20;
       
      (*(volatile unsigned*)0x40010810) |= 0x20;
    } else {
      (*(volatile unsigned*)0x40010810) |= 0x200000;
    }
  }
}


