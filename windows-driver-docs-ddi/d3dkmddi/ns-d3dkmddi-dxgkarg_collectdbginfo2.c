typedef struct _DXGKARG_COLLECTDBGINFO2 {
  UINT                       Reason;
  VOID                       *pBuffer;
  SIZE_T                     BufferSize;
  DXGKARG_COLLECTDBGINFO_EXT *pExtension;
  DXGK_TDR_TYPE              TdrType;
  UINT                       TdrPayloadSize;
  VOID                       *TdrPayload;
} DXGKARG_COLLECTDBGINFO2;