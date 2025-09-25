POFXCALLBACKPROCESSORHALT Pofxcallbackprocessorhalt;

NTSTATUS Pofxcallbackprocessorhalt(
  [in]                ULONG Flags,
  [in, out, optional] PVOID Context,
  [in]                PPROCESSOR_HALT_ROUTINE Halt
)
{...}