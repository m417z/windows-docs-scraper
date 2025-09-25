PRJ_GET_DIRECTORY_ENUMERATION_CB PrjGetDirectoryEnumerationCb;

HRESULT PrjGetDirectoryEnumerationCb(
  [in]           const PRJ_CALLBACK_DATA *callbackData,
  [in]           const GUID *enumerationId,
  [in, optional] PCWSTR searchExpression,
  [in]           PRJ_DIR_ENTRY_BUFFER_HANDLE dirEntryBufferHandle
)
{...}