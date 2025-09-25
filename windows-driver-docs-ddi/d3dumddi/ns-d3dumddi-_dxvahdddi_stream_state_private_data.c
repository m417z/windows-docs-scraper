typedef struct _DXVAHDDDI_STREAM_STATE_PRIVATE_DATA {
  [in]     GUID Guid;
  [in]     UINT DataSize;
  [in/out] VOID *pData;
} DXVAHDDDI_STREAM_STATE_PRIVATE_DATA;