typedef struct _CONFLICT_DETAILS_W {
  ULONG   CD_ulSize;
  ULONG   CD_ulMask;
  DEVINST CD_dnDevInst;
  RES_DES CD_rdResDes;
  ULONG   CD_ulFlags;
  WCHAR   CD_szDescription[MAX_PATH];
} CONFLICT_DETAILS_W, *PCONFLICT_DETAILS_W;