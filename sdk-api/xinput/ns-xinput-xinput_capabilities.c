typedef struct _XINPUT_CAPABILITIES {
  BYTE             Type;
  BYTE             SubType;
  WORD             Flags;
  XINPUT_GAMEPAD   Gamepad;
  XINPUT_VIBRATION Vibration;
} XINPUT_CAPABILITIES, *PXINPUT_CAPABILITIES;