typedef struct _VDS_STORAGE_IDENTIFIER {
  VDS_STORAGE_IDENTIFIER_CODE_SET m_CodeSet;
  VDS_STORAGE_IDENTIFIER_TYPE     m_Type;
  ULONG                           m_cbIdentifier;
  BYTE                            *m_rgbIdentifier;
} VDS_STORAGE_IDENTIFIER;