typedef struct {
  UCHAR     Type;
  struct {
    UCHAR MayOverwritten : 1;
    UCHAR Hidden : 1;
    UCHAR Reserved : 6;
  } Attributes;
  UCHAR     Reserved0[14];
  ULONGLONG SLBA;
  ULONGLONG NLB;
  UCHAR     GUID[16];
  UCHAR     Reserved1[16];
} NVME_LBA_RANGET_TYPE_ENTRY, *PNVME_LBA_RANGET_TYPE_ENTRY;