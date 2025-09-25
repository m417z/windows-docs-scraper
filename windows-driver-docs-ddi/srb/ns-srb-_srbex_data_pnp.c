typedef struct _SRBEX_DATA_PNP {
  SRBEXDATATYPE   Type;
  ULONG           Length;
  UCHAR           PnPSubFunction;
  UCHAR           Reserved[3];
  STOR_PNP_ACTION PnPAction;
  ULONG           SrbPnPFlags;
  ULONG           Reserved1;
} SRBEX_DATA_PNP, *PSRBEX_DATA_PNP;