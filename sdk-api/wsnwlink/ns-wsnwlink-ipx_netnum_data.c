typedef struct _IPX_NETNUM_DATA {
  UCHAR  netnum[4];
  USHORT hopcount;
  USHORT netdelay;
  INT    cardnum;
  UCHAR  router[6];
} IPX_NETNUM_DATA, *PIPX_NETNUM_DATA;