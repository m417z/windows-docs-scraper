NTSYSAPI NTSTATUS RtlVirtualUnwind2(
  [in]                DWORD                          HandlerType,
  [in]                DWORD64                        ImageBase,
  [in]                DWORD64                        ControlPc,
  [in, optional]      PRUNTIME_FUNCTION              FunctionEntry,
  [in, out]           PCONTEXT                       ContextRecord,
  [in, out, optional] PBOOLEAN                       MachineFrameUnwound
  [out]               PVOID                          *HandlerData,
  [out]               PDWORD64                       EstablisherFrame,
  [in, out, optional] PKNONVOLATILE_CONTEXT_POINTERS ContextPointers,
  [in, optional]      PDWORD64                       LowLimit,
  [in, optional]      PDWORD64                       HighLimit,
  [out, optional]     PEXCEPTION_ROUTINE             *HandlerRoutine
  [in]                DWORD                          UnwindFlags
);