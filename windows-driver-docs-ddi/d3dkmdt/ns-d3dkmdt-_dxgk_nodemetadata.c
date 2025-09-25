typedef struct _DXGK_NODEMETADATA {
  DXGK_ENGINE_TYPE        EngineType;
  WCHAR                   FriendlyName[DXGK_MAX_METADATA_NAME_LENGTH];
  DXGK_NODEMETADATA_FLAGS Flags;
  UINT32                  Reserved;
  BOOLEAN                 GpuMmuSupported;
  BOOLEAN                 IoMmuSupported;
} DXGK_NODEMETADATA;