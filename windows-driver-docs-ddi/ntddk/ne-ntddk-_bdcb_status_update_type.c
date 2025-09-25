typedef enum _BDCB_STATUS_UPDATE_TYPE {
  BdCbStatusPrepareForDependencyLoad,
  BdCbStatusPrepareForDriverLoad,
  BdCbStatusPrepareForUnload
} BDCB_STATUS_UPDATE_TYPE, *PBDCB_STATUS_UPDATE_TYPE;