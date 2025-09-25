EVT_SERCX2_CUSTOM_TRANSMIT_TRANSACTION_START EvtSercx2CustomTransmitTransactionStart;

VOID EvtSercx2CustomTransmitTransactionStart(
  [in] SERCX2CUSTOMTRANSMITTRANSACTION CustomTransmitTransaction,
  [in] WDFREQUEST Request,
  [in] PMDL Mdl,
  [in] ULONG Offset,
  [in] ULONG Length
)
{...}