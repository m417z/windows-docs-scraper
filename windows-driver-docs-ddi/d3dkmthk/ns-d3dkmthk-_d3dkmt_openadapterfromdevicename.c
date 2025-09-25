typedef struct _D3DKMT_OPENADAPTERFROMDEVICENAME {
  [in]  PCWSTR        pDeviceName;
  [out] D3DKMT_HANDLE hAdapter;
  [out] LUID          AdapterLuid;
} D3DKMT_OPENADAPTERFROMDEVICENAME;