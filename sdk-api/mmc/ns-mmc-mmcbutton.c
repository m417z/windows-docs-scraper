typedef struct _MMCButton {
  int      nBitmap;
  int      idCommand;
  BYTE     fsState;
  BYTE     fsType;
  LPOLESTR lpButtonText;
  LPOLESTR lpTooltipText;
} MMCBUTTON;