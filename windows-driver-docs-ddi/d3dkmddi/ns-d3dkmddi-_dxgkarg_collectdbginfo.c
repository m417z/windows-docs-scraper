typedef struct _DXGKARG_COLLECTDBGINFO {
  [in]  UINT                       Reason;
  [out] VOID                       *pBuffer;
  [in]  SIZE_T                     BufferSize;
  [out] DXGKARG_COLLECTDBGINFO_EXT *pExtension;
} DXGKARG_COLLECTDBGINFO;