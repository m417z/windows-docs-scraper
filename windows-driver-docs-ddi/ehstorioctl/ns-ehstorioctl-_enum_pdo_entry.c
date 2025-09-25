typedef struct _ENUM_PDO_ENTRY {
  UCHAR type;
  UCHAR state;
  UCHAR capabilities;
  ULONG ulSTID;
  UCHAR bSpecificationMajor;
  UCHAR bSpecificationMinor;
  UCHAR bImplementationMajor;
  UCHAR bImplementationMinor;
  WCHAR *wszDeviceInstancePath[(2  MAX_PATH)+ 1];
} ENUM_PDO_ENTRY, *PENUM_PDO_ENTRY;