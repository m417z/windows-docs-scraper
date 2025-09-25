typedef struct _XINPUT_KEYSTROKE {
  WORD  VirtualKey;
  WCHAR Unicode;
  WORD  Flags;
  BYTE  UserIndex;
  BYTE  HidCode;
} XINPUT_KEYSTROKE, *PXINPUT_KEYSTROKE;