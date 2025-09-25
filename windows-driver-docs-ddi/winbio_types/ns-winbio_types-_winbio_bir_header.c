typedef struct _WINBIO_BIR_HEADER {
  USHORT                   ValidFields;
  WINBIO_BIR_VERSION       HeaderVersion;
  WINBIO_BIR_VERSION       PatronHeaderVersion;
  WINBIO_BIR_DATA_FLAGS    DataFlags;
  WINBIO_BIOMETRIC_TYPE    Type;
  WINBIO_BIOMETRIC_SUBTYPE Subtype;
  WINBIO_BIR_PURPOSE       Purpose;
  WINBIO_BIR_QUALITY       DataQuality;
  LARGE_INTEGER            CreationDate;
  struct {
    LARGE_INTEGER BeginDate;
    LARGE_INTEGER EndDate;
  } ValidityPeriod;
  WINBIO_REGISTERED_FORMAT BiometricDataFormat;
  WINBIO_REGISTERED_FORMAT ProductId;
} WINBIO_BIR_HEADER;