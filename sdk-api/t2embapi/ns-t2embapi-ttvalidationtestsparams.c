typedef struct {
  unsigned long  ulStructSize;
  long           lTestFromSize;
  long           lTestToSize;
  unsigned long  ulCharSet;
  unsigned short usReserved1;
  unsigned short usCharCodeCount;
  unsigned short *pusCharCodeSet;
} TTVALIDATIONTESTSPARAMS;