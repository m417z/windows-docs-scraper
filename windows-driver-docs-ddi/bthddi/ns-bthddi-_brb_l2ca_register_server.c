struct _BRB_L2CA_REGISTER_SERVER {
  BRB_HEADER                     Hdr;
  BTH_ADDR                       BtAddress;
  USHORT                         PSM;
  ULONG                          IndicationFlags;
  PFNBTHPORT_INDICATION_CALLBACK IndicationCallback;
  PVOID                          IndicationCallbackContext;
  PVOID                          ReferenceObject;
  OUT L2CAP_SERVER_HANDLE        ServerHandle;
};