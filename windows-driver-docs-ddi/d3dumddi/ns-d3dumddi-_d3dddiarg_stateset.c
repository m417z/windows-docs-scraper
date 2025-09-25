typedef struct _D3DDDIARG_STATESET {
  [in]     UINT              Operation;
  [in]     D3DSTATEBLOCKTYPE StateBlockType;
  [in/out] HANDLE            hStateSet;
} D3DDDIARG_STATESET;