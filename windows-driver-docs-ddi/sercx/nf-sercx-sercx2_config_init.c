VOID SERCX2_CONFIG_INIT(
  [out] SERCX2_CONFIG           *Config,
  [in]  PFN_SERCX2_APPLY_CONFIG EvtSerCx2ApplyConfig,
  [in]  PFN_SERCX2_CONTROL      EvtSerCx2Control,
  [in]  PFN_SERCX2_PURGE_FIFOS  EvtSerCx2PurgeFifos
);