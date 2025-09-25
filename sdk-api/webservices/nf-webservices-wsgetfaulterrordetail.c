HRESULT WsGetFaultErrorDetail(
  [in]           WS_ERROR                          *error,
  [in]           const WS_FAULT_DETAIL_DESCRIPTION *faultDetailDescription,
  [in]           WS_READ_OPTION                    readOption,
  [in, optional] WS_HEAP                           *heap,
                 void                              *value,
  [in]           ULONG                             valueSize
);