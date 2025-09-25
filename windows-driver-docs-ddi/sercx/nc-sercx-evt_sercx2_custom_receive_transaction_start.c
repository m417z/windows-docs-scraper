EVT_SERCX2_CUSTOM_RECEIVE_TRANSACTION_START EvtSercx2CustomReceiveTransactionStart;

VOID EvtSercx2CustomReceiveTransactionStart(
  [in] SERCX2CUSTOMRECEIVETRANSACTION CustomReceiveTransaction,
  [in] WDFREQUEST Request,
  [in] PMDL Mdl,
  [in] ULONG Offset,
  [in] ULONG Length
)
{...}