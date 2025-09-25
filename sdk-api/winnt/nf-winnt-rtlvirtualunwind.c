NTSYSAPI PEXCEPTION_ROUTINE RtlVirtualUnwind(
  [in]                DWORD                          HandlerType,
  [in]                DWORD64                        ImageBase,
  [in]                DWORD64                        ControlPc,
  [in]                PRUNTIME_FUNCTION              FunctionEntry,
  [in, out]           PCONTEXT                       ContextRecord,
  [out]               PVOID                          *HandlerData,
  [out]               PDWORD64                       EstablisherFrame,
  [in, out, optional] PKNONVOLATILE_CONTEXT_POINTERS ContextPointers
);