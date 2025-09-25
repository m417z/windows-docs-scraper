HRESULT GetDescription(
  [in]            ULONG                       Register,
  [out, optional] PSTR                        NameBuffer,
  [in]            ULONG                       NameBufferSize,
  [out, optional] PULONG                      NameSize,
  [out, optional] PDEBUG_REGISTER_DESCRIPTION Desc
);