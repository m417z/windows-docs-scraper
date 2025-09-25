EVT_SERCX2_SELECT_NEXT_TRANSMIT_TRANSACTION_TYPE EvtSercx2SelectNextTransmitTransactionType;

SERCX2_TRANSACTION_TYPE EvtSercx2SelectNextTransmitTransactionType(
  [in]  WDFDEVICE Device,
  [in]  PMDL Mdl,
  [in]  ULONG Offset,
  [in]  ULONG RemainingLength,
  [out] SERCX2CUSTOMTRANSMIT *CustomTransmit,
  [out] PULONG NextTransactionLength
)
{...}