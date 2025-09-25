typedef struct _MFCONTENTPROTECTIONDEVICE_OUTPUT_DATA {
  DWORD    PrivateDataByteCount;
  DWORD    MaxHWProtectionDataByteCount;
  DWORD    HWProtectionDataByteCount;
  HRESULT  Status;
  LONGLONG TransportTimeInHundredsOfNanoseconds;
  LONGLONG ExecutionTimeInHundredsOfNanoseconds;
  BYTE     OutputData[4];
} MFCONTENTPROTECTIONDEVICE_OUTPUT_DATA;