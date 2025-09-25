typedef struct CS_Des_s {
  DWORD CSD_SignatureLength;
  DWORD CSD_LegacyDataOffset;
  DWORD CSD_LegacyDataSize;
  DWORD CSD_Flags;
  GUID  CSD_ClassGuid;
  BYTE  CSD_Signature[ANYSIZE_ARRAY];
} CS_DES, *PCS_DES;