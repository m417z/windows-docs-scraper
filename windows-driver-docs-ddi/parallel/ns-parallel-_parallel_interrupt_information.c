typedef struct _PARALLEL_INTERRUPT_INFORMATION {
  PKINTERRUPT                    InterruptObject;
  PPARALLEL_TRY_ALLOCATE_ROUTINE TryAllocatePortAtInterruptLevel;
  PPARALLEL_FREE_ROUTINE         FreePortFromInterruptLevel;
  PVOID                          Context;
} PARALLEL_INTERRUPT_INFORMATION, *PPARALLEL_INTERRUPT_INFORMATION;