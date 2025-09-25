LSA_CREATE_THREAD LsaCreateThread;

HANDLE LsaCreateThread(
  [in]  SEC_ATTRS SecurityAttributes,
  [in]  ULONG StackSize,
  [in]  SEC_THREAD_START StartFunction,
  [in]  PVOID ThreadParameter,
  [in]  ULONG CreationFlags,
  [out] PULONG ThreadId
)
{...}