HRESULT WsRegisterOperationForCancel(
  [in]           const WS_OPERATION_CONTEXT       *context,
  [in]           WS_OPERATION_CANCEL_CALLBACK     cancelCallback,
  [in, optional] WS_OPERATION_FREE_STATE_CALLBACK freestateCallback,
  [in, optional] void                             *userState,
  [in, optional] WS_ERROR                         *error
);