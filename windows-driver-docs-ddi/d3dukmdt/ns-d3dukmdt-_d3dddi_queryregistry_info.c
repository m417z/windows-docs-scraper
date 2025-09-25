typedef struct _D3DDDI_QUERYREGISTRY_INFO {
  D3DDDI_QUERYREGISTRY_TYPE   QueryType;
  D3DDDI_QUERYREGISTRY_FLAGS  QueryFlags;
  WCHAR                       ValueName[MAX_PATH];
  ULONG                       ValueType;
  ULONG                       PhysicalAdapterIndex;
  ULONG                       OutputValueSize;
  D3DDDI_QUERYREGISTRY_STATUS Status;
  union {
    DWORD                 OutputDword;
    D3DKMT_ALIGN64 UINT64 OutputQword;
    WCHAR                 OutputString[1];
    BYTE                  OutputBinary[1];
  };
} D3DDDI_QUERYREGISTRY_INFO;