HRESULT WsCreateFaultFromError(
  [in]  WS_ERROR            *error,
  [in]  HRESULT             faultErrorCode,
  [in]  WS_FAULT_DISCLOSURE faultDisclosure,
  [in]  WS_HEAP             *heap,
  [out] WS_FAULT            *fault
);