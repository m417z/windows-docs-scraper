HRESULT CfSetPinState(
  [in]                HANDLE           FileHandle,
  [in]                CF_PIN_STATE     PinState,
  [in]                CF_SET_PIN_FLAGS PinFlags,
  [in, out, optional] LPOVERLAPPED     Overlapped
);