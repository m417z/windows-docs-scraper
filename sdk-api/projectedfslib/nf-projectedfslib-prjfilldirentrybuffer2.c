HRESULT PrjFillDirEntryBuffer2(
  [in]           PRJ_DIR_ENTRY_BUFFER_HANDLE dirEntryBufferHandle,
  [in]           PCWSTR                      fileName,
  [in, optional] PRJ_FILE_BASIC_INFO         *fileBasicInfo,
  [in, optional] PRJ_EXTENDED_INFO           *extendedInfo
);