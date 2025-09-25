PENABLECALLBACK Penablecallback;

VOID Penablecallback(
  [in]           LPCGUID SourceId,
  [in]           ULONG IsEnabled,
  [in]           UCHAR Level,
  [in]           ULONGLONG MatchAnyKeyword,
                 ULONGLONG MatchAllKeyword,
  [in, optional] PEVENT_FILTER_DESCRIPTOR FilterData,
  [in, optional] PVOID CallbackContext
)
{...}