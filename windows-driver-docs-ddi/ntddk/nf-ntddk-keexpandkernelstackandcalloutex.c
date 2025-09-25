NTSTATUS KeExpandKernelStackAndCalloutEx(
  PEXPAND_STACK_CALLOUT Callout,
  PVOID                 Parameter,
  SIZE_T                Size,
  BOOLEAN               Wait,
  PVOID                 Context
);