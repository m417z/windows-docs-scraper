typedef struct _VDS_LUN_INFORMATION {
  ULONG                            m_version;
  BYTE                             m_DeviceType;
  BYTE                             m_DeviceTypeModifier;
  BOOL                             m_bCommandQueueing;
  VDS_STORAGE_BUS_TYPE             m_BusType;
  char                             *m_szVendorId;
  char                             *m_szProductId;
  char                             *m_szProductRevision;
  char                             *m_szSerialNumber;
  GUID                             m_diskSignature;
  VDS_STORAGE_DEVICE_ID_DESCRIPTOR m_deviceIdDescriptor;
  ULONG                            m_cInterconnects;
  VDS_INTERCONNECT                 *m_rgInterconnects;
} VDS_LUN_INFORMATION;