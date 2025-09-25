typedef struct _MOUSE_INPUT_DATA {
  USHORT UnitId;
  USHORT Flags;
  union {
    ULONG Buttons;
    struct {
      USHORT ButtonFlags;
      USHORT ButtonData;
    };
  };
  ULONG  RawButtons;
  LONG   LastX;
  LONG   LastY;
  ULONG  ExtraInformation;
} MOUSE_INPUT_DATA, *PMOUSE_INPUT_DATA;