typedef struct _D3DKMT_OPENADAPTERFROMLUID {
        LUID          AdapterLuid;
  [out] D3DKMT_HANDLE hAdapter;
} D3DKMT_OPENADAPTERFROMLUID;