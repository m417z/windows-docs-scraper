typedef struct _D3DDDIARG_GETCAPS {
  [in]     D3DDDICAPS_TYPE Type;
  [in]     VOID            *pInfo;
  [out]    VOID            *pData;
  [in/out] UINT            DataSize;
} D3DDDIARG_GETCAPS;