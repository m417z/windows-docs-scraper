typedef struct _WOW64_FLOATING_SAVE_AREA {
  DWORD ControlWord;
  DWORD StatusWord;
  DWORD TagWord;
  DWORD ErrorOffset;
  DWORD ErrorSelector;
  DWORD DataOffset;
  DWORD DataSelector;
  BYTE  RegisterArea[WOW64_SIZE_OF_80387_REGISTERS];
  DWORD Cr0NpxState;
} WOW64_FLOATING_SAVE_AREA;