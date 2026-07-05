typedef struct _D3DKMT_CONNECT_DOORBELL {
  D3DKMT_HANDLE                 hHwQueue;
  D3DKMT_CONNECT_DOORBELL_FLAGS Flags;
  D3DDDI_DOORBELLMAPPING        DoorbellMapping;
  BYTE                          Reserved[64];
} D3DKMT_CONNECT_DOORBELL;