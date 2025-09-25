GPIO_CLIENT_PRE_PROCESS_CONTROLLER_INTERRUPT GpioClientPreProcessControllerInterrupt;

NTSTATUS GpioClientPreProcessControllerInterrupt(
  [in] PVOID Context,
  [in] BANK_ID BankId,
       ULONG64 EnabledMask
)
{...}