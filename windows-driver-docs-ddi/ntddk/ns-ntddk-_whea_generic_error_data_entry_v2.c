typedef struct _WHEA_GENERIC_ERROR_DATA_ENTRY_V2 {
  GUID                SectionType;
  WHEA_ERROR_SEVERITY ErrorSeverity;
  WHEA_REVISION       Revision;
  UCHAR               ValidBits;
  UCHAR               Flags;
  ULONG               ErrorDataLength;
  GUID                FRUId;
  UCHAR               FRUText[WHEA_GENERIC_ENTRY_TEXT_LEN];
  WHEA_TIMESTAMP      Timestamp;
  UCHAR               Data[1];
} WHEA_GENERIC_ERROR_DATA_ENTRY_V2, *PWHEA_GENERIC_ERROR_DATA_ENTRY_V2, WHEA_GENERIC_ERROR_DATA_ENTRY, *PWHEA_GENERIC_ERROR_DATA_ENTRY;