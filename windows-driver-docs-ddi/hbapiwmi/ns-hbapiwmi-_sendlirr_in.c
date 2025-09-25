typedef struct _SendLIRR_IN {
  UCHAR SourceWWN[8];
  UCHAR DestWWN[8];
  UCHAR Function;
  UCHAR Type;
} SendLIRR_IN, *PSendLIRR_IN;