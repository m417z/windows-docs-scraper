HRESULT CfGetPlaceholderRangeInfoForHydration(
  [in]            CF_CONNECTION_KEY               ConnectionKey,
  [in]            CF_TRANSFER_KEY                 TransferKey,
  [in]            LARGE_INTEGER                   FileId,
  [in]            CF_PLACEHOLDER_RANGE_INFO_CLASS InfoClass,
  [in]            LARGE_INTEGER                   StartingOffset,
  [in]            LARGE_INTEGER                   RangeLength,
  [out]           PVOID                           InfoBuffer,
  [in]            DWORD                           InfoBufferSize,
  [out, optional] PDWORD                          InfoBufferWritten
);