struct _BRB_L2CA_UNREGISTER_SERVER {
  BRB_HEADER Hdr;
  BTH_ADDR   BtAddress;
  PVOID      ServerHandle;
  USHORT     Psm;
};