typedef struct _IPX_ADDRESS_DATA {
  INT     adapternum;
  UCHAR   netnum[4];
  UCHAR   nodenum[6];
  BOOLEAN wan;
  BOOLEAN status;
  INT     maxpkt;
  ULONG   linkspeed;
} IPX_ADDRESS_DATA, *PIPX_ADDRESS_DATA;