typedef union {
  struct {
    ULONG LBAF : 4;
    ULONG MS : 1;
    ULONG PI : 3;
    ULONG PIL : 1;
    ULONG SES : 3;
    ULONG ZF : 2;
    ULONG Reserved : 18;
  } DUMMYSTRUCTNAME;
  ULONG  AsUlong;
} NVME_CDW10_FORMAT_NVM, *PNVME_CDW10_FORMAT_NVM;