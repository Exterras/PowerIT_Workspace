static void Delay(volatile unsigned int cnt);

int main(){
  // RCC Base Address = 0x40021000
  // RCC_CR offset = 0x00
  // HSION = 0x1
  // (*(volatile unsigned*)0x40021000) |= 0x1
  
  // RCC Base Address = 0x40021000
  // RCC_CFGR offset = 0x04
  // SW = 0x0; HSI selected as system clock
  // (*(volatile unsigned*)0x40021004) |= 0x0
  
  // RCC Base Address = 0x40021000
  // APB2ENR offset = 0x18
  // IOPAEN = 0x4; 
  // (*(volatile unsigned*)0x40021018) |= 0x4
  
  // PORTA Base Address = 0x40010800
  // CRL offset = 0x00
  // CNFy = 0x00(push-pull); MODE = 0x01(max, 10MHz)
  // (*(volatile unsigned*)0x40010800) = 0x0;
  // (*(volatile unsigned*)0x40010800) |= 0x100000;
  
  while(1){
    // PORTA Base Address = 0x40010800
    // BSRR offset = 0x10
    // Set = 0x20; Reset = 0x0200000
    (*(volatile unsigned*)0x40010800) |= 0x20;
    Delay(30000);
    (*(volatile unsigned*)0x40010800) |= 0x200000;
    Delay(30000);
  }
}

static void Delay(volatile unsigned int cnt){
  for(; cnt > 0; cnt--);
}
