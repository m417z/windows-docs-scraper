typedef struct D3D10_2DDIARG_GETCAPS {
  [in]     D3D10_2DDICAPS_TYPE Type;
  [in]     VOID                *pInfo;
  [out]    VOID                *pData;
  [in/out] UINT                DataSize;
} D3D10_2DDIARG_GETCAPS;