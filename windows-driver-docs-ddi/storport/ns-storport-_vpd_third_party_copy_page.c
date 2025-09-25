typedef struct _VPD_THIRD_PARTY_COPY_PAGE {
  UCHAR DeviceType : 5;
  UCHAR DeviceTypeQualifier : 3;
  UCHAR PageCode;
  UCHAR PageLength[2];
  UCHAR ThirdPartyCopyDescriptors[ANYSIZE_ARRAY];
} VPD_THIRD_PARTY_COPY_PAGE, *PVPD_THIRD_PARTY_COPY_PAGE;