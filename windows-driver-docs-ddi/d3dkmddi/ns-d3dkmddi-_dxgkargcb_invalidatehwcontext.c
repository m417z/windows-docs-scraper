typedef struct _DXGKARGCB_INVALIDATEHWCONTEXT {
  [in] HANDLE                        hAdapter;
  [in] HANDLE                        hHwContext;
  [in] DXGK_INVALIDATEHWCONTEXTFLAGS Flags;
} DXGKARGCB_INVALIDATEHWCONTEXT;