ULONG TcAddFlow(
  [in]  HANDLE       IfcHandle,
  [in]  HANDLE       ClFlowCtx,
  [in]  ULONG        Flags,
  [in]  PTC_GEN_FLOW pGenericFlow,
  [out] PHANDLE      pFlowHandle
);