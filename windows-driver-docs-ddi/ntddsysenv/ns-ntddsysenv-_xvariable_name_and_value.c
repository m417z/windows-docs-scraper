typedef struct _XVARIABLE_NAME_AND_VALUE {
  ULONG NextEntryOffset;
  ULONG ValueOffset;
  ULONG ValueLength;
  ULONG Attributes;
  GUID  VendorGuid;
  WCHAR Name[ANYSIZE_ARRAY];
} XVARIABLE_NAME_AND_VALUE, *PXVARIABLE_NAME_AND_VALUE;