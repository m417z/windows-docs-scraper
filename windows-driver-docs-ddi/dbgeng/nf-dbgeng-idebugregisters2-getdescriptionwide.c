HRESULT GetDescriptionWide(
  [in]            ULONG                       Register,
  [out, optional] PWSTR                       NameBuffer,
  [in]            ULONG                       NameBufferSize,
  [out, optional] PULONG                      NameSize,
  [out, optional] PDEBUG_REGISTER_DESCRIPTION Desc
);