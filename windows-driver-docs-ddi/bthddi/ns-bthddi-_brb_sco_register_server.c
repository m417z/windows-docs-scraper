struct _BRB_SCO_REGISTER_SERVER {
  BRB_HEADER                 Hdr;
  BTH_ADDR                   BtAddress;
  ULONG                      Reserved;
  ULONG                      IndicationFlags;
  PFNSCO_INDICATION_CALLBACK IndicationCallback;
  PVOID                      IndicationCallbackContext;
  PVOID                      ReferenceObject;
  SCO_SERVER_HANDLE          ServerHandle;
};