typedef struct _IMEWRD {
  WCHAR  *pwchReading;
  WCHAR  *pwchDisplay;
  union {
    ULONG ulPos;
    struct {
      WORD nPos1;
      WORD nPos2;
    };
  };
  ULONG  rgulAttrs[2];
  INT    cbComment;
  IMEUCT uct;
  VOID   *pvComment;
} IMEWRD, *PIMEWRD;