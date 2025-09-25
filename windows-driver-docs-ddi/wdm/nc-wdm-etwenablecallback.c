ETWENABLECALLBACK Etwenablecallback;

VOID Etwenablecallback(
  [in]                LPCGUID SourceId,
                      ULONG ControlCode,
  [in]                UCHAR Level,
  [in]                ULONGLONG MatchAnyKeyword,
  [in]                ULONGLONG MatchAllKeyword,
  [in, optional]      PEVENT_FILTER_DESCRIPTOR FilterData,
  [in, out, optional] PVOID CallbackContext
)
{...}