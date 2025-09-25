HRESULT GetManagedStatus(
  [out, optional] PULONG Flags,
  [in]            ULONG  WhichString,
  [out]           PSTR   String,
  [in]            ULONG  StringSize,
  [out, optional] PULONG StringNeeded
);