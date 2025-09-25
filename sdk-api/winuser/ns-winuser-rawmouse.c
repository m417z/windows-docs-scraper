typedef struct tagRAWMOUSE {
  USHORT usFlags;
  union {
    ULONG ulButtons;
    struct {
      USHORT usButtonFlags;
      USHORT usButtonData;
    } DUMMYSTRUCTNAME;
  } DUMMYUNIONNAME;
  ULONG  ulRawButtons;
  LONG   lLastX;
  LONG   lLastY;
  ULONG  ulExtraInformation;
} RAWMOUSE, *PRAWMOUSE, *LPRAWMOUSE;