PWINDBG_SET_THREAD_CONTEXT_ROUTINE PwindbgSetThreadContextRoutine;

ULONG PwindbgSetThreadContextRoutine(
        ULONG Processor,
  [out] PCONTEXT lpContext,
  [in]  ULONG cbSizeOfContext
)
{...}