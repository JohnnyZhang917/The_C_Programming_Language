int main()
{
  unsigned int a=0xFFFEFDFC;
  unsigned int *p=&a;
  unsigned char *p0=p;
  unsigned int b1=*p0;
  unsigned int b2=*(p0+1);
}

// so we get:
//  p0 p0+1 p0+2 p0+3
//  FC  FD  FE   FF

// Intel x86 is Little endian