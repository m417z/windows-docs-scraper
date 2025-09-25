NTSTATUS WdfDriverRegisterTraceInfo(
  [in] PDRIVER_OBJECT         DriverObject,
  [in] PFN_WDF_TRACE_CALLBACK EvtTraceCallback,
  [in] PVOID                  ControlBlock
);