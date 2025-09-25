typedef struct _MFCONTENTPROTECTIONDEVICE_INPUT_DATA {
  DWORD HWProtectionFunctionID;
  DWORD PrivateDataByteCount;
  DWORD HWProtectionDataByteCount;
  DWORD Reserved;
  BYTE  InputData[4];
} MFCONTENTPROTECTIONDEVICE_INPUT_DATA;