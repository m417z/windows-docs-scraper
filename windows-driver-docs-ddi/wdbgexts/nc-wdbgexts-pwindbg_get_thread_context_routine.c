PWINDBG_GET_THREAD_CONTEXT_ROUTINE PwindbgGetThreadContextRoutine;

ULONG PwindbgGetThreadContextRoutine(
        ULONG Processor,
  [out] PCONTEXT lpContext,
  [in]  ULONG cbSizeOfContext
)
{...}