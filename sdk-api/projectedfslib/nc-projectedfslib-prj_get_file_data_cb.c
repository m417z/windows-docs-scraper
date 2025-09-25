PRJ_GET_FILE_DATA_CB PrjGetFileDataCb;

HRESULT PrjGetFileDataCb(
  [in] const PRJ_CALLBACK_DATA *callbackData,
  [in] UINT64 byteOffset,
  [in] UINT32 length
)
{...}