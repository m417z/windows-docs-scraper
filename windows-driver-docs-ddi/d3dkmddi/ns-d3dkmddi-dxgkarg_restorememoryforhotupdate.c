typedef struct _DXGKARG_RESTOREMEMORYFORHOTUPDATE {
  [in] DXGK_RESTOREMEMORYFORHOTUPDATEFLAGS Flags;
  [in] PMDL                                pDataMdl;
  [in] UINT                                MetaDataSize;
  [in] PVOID                               pMetaData;
} DXGKARG_RESTOREMEMORYFORHOTUPDATE;