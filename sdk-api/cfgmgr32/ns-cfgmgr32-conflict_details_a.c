typedef struct _CONFLICT_DETAILS_A {
  ULONG   CD_ulSize;
  ULONG   CD_ulMask;
  DEVINST CD_dnDevInst;
  RES_DES CD_rdResDes;
  ULONG   CD_ulFlags;
  CHAR    CD_szDescription[MAX_PATH];
} CONFLICT_DETAILS_A, *PCONFLICT_DETAILS_A;