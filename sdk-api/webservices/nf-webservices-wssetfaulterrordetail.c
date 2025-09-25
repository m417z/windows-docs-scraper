HRESULT WsSetFaultErrorDetail(
  [in] WS_ERROR                          *error,
  [in] const WS_FAULT_DETAIL_DESCRIPTION *faultDetailDescription,
  [in] WS_WRITE_OPTION                   writeOption,
       const void                        *value,
  [in] ULONG                             valueSize
);