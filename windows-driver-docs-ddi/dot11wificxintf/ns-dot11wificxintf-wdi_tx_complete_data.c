typedef struct _WDI_TX_COMPLETE_DATA {
  UINT16           SeqCtl;
  UINT8            PnLength;
  UINT8            RetryCount;
  UINT16           wPad;
  WDI_TXRX_MPDU_PN MpduPN;
  UINT64           ReplayIHVReserved0;
  UINT64           ReplayIHVReserved1;
} WDI_TX_COMPLETE_DATA, *PWDI_TX_COMPLETE_DATA;