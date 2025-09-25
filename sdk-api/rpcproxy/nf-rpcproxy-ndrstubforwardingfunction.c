void NdrStubForwardingFunction(
  [in]      IRpcStubBuffer    *This,
  [in]      IRpcChannelBuffer *pChannel,
  [in, out] PRPC_MESSAGE      pmsg,
  [out]     DWORD             *pdwStubPhase
);