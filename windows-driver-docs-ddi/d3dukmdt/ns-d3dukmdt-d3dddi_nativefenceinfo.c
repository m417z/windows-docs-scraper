typedef struct _D3DDDI_NATIVEFENCEINFO {
  D3DKMT_ALIGN64 UINT64              InitialFenceValue;
  UINT                               EngineAffinity;
  D3DDDI_NATIVEFENCE_TYPE            Type;
  D3DDDI_SYNCHRONIZATIONOBJECT_FLAGS Flags;
  D3DDDI_NATIVEFENCEMAPPING          NativeFenceMapping;
  UINT                               PhysicalAdapterIndex;
  BYTE                               Reserved[24];
} D3DDDI_NATIVEFENCEINFO;