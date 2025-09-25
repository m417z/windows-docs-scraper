typedef struct _NDIS_MINIPORT_CO_CHARACTERISTICS {
  NDIS_OBJECT_HEADER                 Header;
  ULONG                              Flags;
  W_CO_CREATE_VC_HANDLER             CoCreateVcHandler;
  W_CO_DELETE_VC_HANDLER             CoDeleteVcHandler;
  W_CO_ACTIVATE_VC_HANDLER           CoActivateVcHandler;
  W_CO_DEACTIVATE_VC_HANDLER         CoDeactivateVcHandler;
  W_CO_SEND_NET_BUFFER_LISTS_HANDLER CoSendNetBufferListsHandler;
  W_CO_OID_REQUEST_HANDLER           CoOidRequestHandler;
} NDIS_MINIPORT_CO_CHARACTERISTICS, *PNDIS_MINIPORT_CO_CHARACTERISTICS;