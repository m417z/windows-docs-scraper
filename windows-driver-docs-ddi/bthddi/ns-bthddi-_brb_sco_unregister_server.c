struct _BRB_SCO_UNREGISTER_SERVER {
  BRB_HEADER Hdr;
  BTH_ADDR   BtAddress;
  PVOID      ServerHandle;
};