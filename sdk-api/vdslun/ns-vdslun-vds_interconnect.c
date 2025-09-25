typedef struct _VDS_INTERCONNECT {
  VDS_INTERCONNECT_ADDRESS_TYPE m_addressType;
  ULONG                         m_cbPort;
  BYTE                          *m_pbPort;
  ULONG                         m_cbAddress;
  BYTE                          *m_pbAddress;
} VDS_INTERCONNECT;