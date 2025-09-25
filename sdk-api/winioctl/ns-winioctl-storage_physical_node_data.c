typedef struct _STORAGE_PHYSICAL_NODE_DATA {
  DWORD NodeId;
  DWORD AdapterCount;
  DWORD AdapterDataLength;
  DWORD AdapterDataOffset;
  DWORD DeviceCount;
  DWORD DeviceDataLength;
  DWORD DeviceDataOffset;
  DWORD Reserved[3];
} STORAGE_PHYSICAL_NODE_DATA, *PSTORAGE_PHYSICAL_NODE_DATA;