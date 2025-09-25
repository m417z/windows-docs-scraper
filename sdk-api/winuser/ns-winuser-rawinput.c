typedef struct tagRAWINPUT {
  RAWINPUTHEADER header;
  union {
    RAWMOUSE    mouse;
    RAWKEYBOARD keyboard;
    RAWHID      hid;
  } data;
} RAWINPUT, *PRAWINPUT, *LPRAWINPUT;