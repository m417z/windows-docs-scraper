PMRX_SRVCALL_WINNER_NOTIFY PmrxSrvcallWinnerNotify;

NTSTATUS PmrxSrvcallWinnerNotify(
  IN OUT PMRX_SRV_CALL SrvCall,
  IN BOOLEAN ThisMinirdrIsTheWinner,
  IN OUT PVOID RecommunicateContext
)
{...}