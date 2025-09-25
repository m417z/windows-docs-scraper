typedef struct _DXGKARGCB_SAVEMEMORYFORHOTUPDATE {
  [in]           UINT                  NumDataMemoryRanges;
  [in, optional] DXGK_KSR_MEMORY_RANGE *pDataMemoryRanges;
  [in, optional] PMDL                  pDataMdl;
  [in]           UINT                  DataSize;
  [in, optional] PVOID                 pData;
  [in]           UINT                  MetaDataSize;
  [in, optional] BYTE                  *pMetaData;
} DXGKARGCB_SAVEMEMORYFORHOTUPDATE;