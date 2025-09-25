typedef struct _VDS_STORAGE_DEVICE_ID_DESCRIPTOR {
  ULONG                  m_version;
  ULONG                  m_cIdentifiers;
  VDS_STORAGE_IDENTIFIER *m_rgIdentifiers;
} VDS_STORAGE_DEVICE_ID_DESCRIPTOR;