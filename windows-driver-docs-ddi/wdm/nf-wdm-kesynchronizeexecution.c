BOOLEAN KeSynchronizeExecution(
  [in, out]      PKINTERRUPT            Interrupt,
  [in]           PKSYNCHRONIZE_ROUTINE  SynchronizeRoutine,
  [in, optional] __drv_aliasesMem PVOID SynchronizeContext
);