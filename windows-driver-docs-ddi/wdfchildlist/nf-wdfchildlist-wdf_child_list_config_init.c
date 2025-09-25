VOID WDF_CHILD_LIST_CONFIG_INIT(
  [out] PWDF_CHILD_LIST_CONFIG           Config,
  [in]  ULONG                            IdentificationDescriptionSize,
  [in]  PFN_WDF_CHILD_LIST_CREATE_DEVICE EvtChildListCreateDevice
);