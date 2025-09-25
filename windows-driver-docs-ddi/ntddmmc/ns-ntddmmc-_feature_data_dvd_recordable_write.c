typedef struct _FEATURE_DATA_DVD_RECORDABLE_WRITE {
  FEATURE_HEADER Header;
  UCHAR          Reserved1 : 1;
  UCHAR          DVD_RW : 1;
  UCHAR          TestWrite : 1;
  UCHAR          RDualLayer : 1;
  UCHAR          Reserved02 : 2;
  UCHAR          BufferUnderrunFree : 1;
  UCHAR          Reserved3 : 1;
  UCHAR          Reserved4[3];
} FEATURE_DATA_DVD_RECORDABLE_WRITE, *PFEATURE_DATA_DVD_RECORDABLE_WRITE;