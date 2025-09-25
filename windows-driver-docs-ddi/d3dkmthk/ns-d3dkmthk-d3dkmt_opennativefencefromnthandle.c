typedef struct _D3DKMT_OPENNATIVEFENCEFROMNTHANDLE {
  HANDLE                             hNtHandle;
  D3DKMT_HANDLE                      hDevice;
  UINT                               EngineAffinity;
  D3DDDI_SYNCHRONIZATIONOBJECT_FLAGS Flags;
  D3DKMT_HANDLE                      hSyncObject;
  D3DDDI_NATIVEFENCEMAPPING          NativeFenceMapping;
  BYTE                               PrivateDriverData[D3DDDI_NATIVE_FENCE_PDD_SIZE];
  BYTE                               Reserved[32];
} D3DKMT_OPENNATIVEFENCEFROMNTHANDLE;