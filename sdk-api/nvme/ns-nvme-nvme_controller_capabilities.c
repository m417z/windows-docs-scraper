typedef union {
  struct {
    ULONGLONG MQES : 16;
    ULONGLONG CQR : 1;
    ULONGLONG AMS_WeightedRoundRobinWithUrgent : 1;
    ULONGLONG AMS_VendorSpecific : 1;
    ULONGLONG Reserved0 : 5;
    ULONGLONG TO : 8;
    ULONGLONG DSTRD : 4;
    ULONGLONG NSSRS : 1;
    ULONGLONG CSS_NVM : 1;
    ULONGLONG CSS_Reserved0 : 1;
    ULONGLONG CSS_Reserved1 : 1;
    ULONGLONG CSS_Reserved2 : 1;
    ULONGLONG CSS_Reserved3 : 1;
    ULONGLONG CSS_Reserved4 : 1;
    ULONGLONG CSS_MultipleIo : 1;
    ULONGLONG CSS_AdminOnly : 1;
    ULONGLONG Reserved2 : 3;
    ULONGLONG MPSMIN : 4;
    ULONGLONG MPSMAX : 4;
    ULONGLONG Reserved3 : 8;
  } DUMMYSTRUCTNAME;
  ULONGLONG AsUlonglong;
} NVME_CONTROLLER_CAPABILITIES, *PNVME_CONTROLLER_CAPABILITIES;