typedef struct _DXGKMDT_OPM_STANDARD_INFORMATION {
  DXGKMDT_OPM_RANDOM_NUMBER rnRandomNumber;
  ULONG                     ulStatusFlags;
  ULONG                     ulInformation;
  ULONG                     ulReserved;
  ULONG                     ulReserved2;
} DXGKMDT_OPM_STANDARD_INFORMATION;