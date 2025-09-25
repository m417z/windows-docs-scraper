struct _DEV_BROADCAST_USERDEFINED {
  struct _DEV_BROADCAST_HDR dbud_dbh;
  char                      dbud_szName[1];
};