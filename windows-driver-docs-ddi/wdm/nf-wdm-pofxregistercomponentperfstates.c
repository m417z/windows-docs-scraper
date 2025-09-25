NTSTATUS PoFxRegisterComponentPerfStates(
  [in]  POHANDLE                             Handle,
  [in]  ULONG                                Component,
  [in]  ULONGLONG                            Flags,
  [in]  PPO_FX_COMPONENT_PERF_STATE_CALLBACK ComponentPerfStateCallback,
  [in]  PPO_FX_COMPONENT_PERF_INFO           InputStateInfo,
  [out] PPO_FX_COMPONENT_PERF_INFO           *OutputStateInfo
);