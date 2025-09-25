typedef struct _KS_DVDCOPY_TITLEKEY {
  ULONG KeyFlags;
  ULONG ReservedNT[2];
  UCHAR TitleKey[6];
  UCHAR Reserved[2];
} KS_DVDCOPY_TITLEKEY, *PKS_DVDCOPY_TITLEKEY;