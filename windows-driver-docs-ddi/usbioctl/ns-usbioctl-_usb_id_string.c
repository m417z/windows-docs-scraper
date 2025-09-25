typedef struct _USB_ID_STRING {
  USHORT LanguageId;
  USHORT Pad;
  ULONG  LengthInBytes;
  PWCHAR Buffer;
} USB_ID_STRING, *PUSB_ID_STRING;