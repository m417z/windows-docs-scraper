typedef struct _QCMINFO {
  HMENU               hmenu;
  UINT                indexMenu;
  UINT                idCmdFirst;
  UINT                idCmdLast;
  QCMINFO_IDMAP const *pIdMap;
} QCMINFO;