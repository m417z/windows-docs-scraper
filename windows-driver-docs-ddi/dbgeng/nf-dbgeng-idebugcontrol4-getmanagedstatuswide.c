HRESULT GetManagedStatusWide(
  [out, optional] PULONG Flags,
  [in]            ULONG  WhichString,
  [out]           PWSTR  String,
  [in]            ULONG  StringSize,
  [out, optional] PULONG StringNeeded
);