EVT_SERCX2_SELECT_NEXT_RECEIVE_TRANSACTION_TYPE EvtSercx2SelectNextReceiveTransactionType;

SERCX2_TRANSACTION_TYPE EvtSercx2SelectNextReceiveTransactionType(
  [in]  WDFDEVICE Device,
  [in]  PMDL Mdl,
  [in]  ULONG Offset,
  [in]  ULONG RemainingLength,
  [out] SERCX2CUSTOMRECEIVE *CustomReceive,
  [out] PULONG NextTransactionLength
)
{...}