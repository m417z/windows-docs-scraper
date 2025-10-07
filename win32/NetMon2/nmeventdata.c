typedef struct {
  BYTE         Version;
  DWORD        EventIdent;
  DWORD        Flags;
  DWORD        Severity;
  BYTE         NumColumns;
  LPSTR        szSourceName;
  LPSTR        szEventName;
  LPSTR        szDescription;
  LPSTR        szMachine;
  JTYPE        Justification;
  LPSTR        szUrl;
  SYSTEMTIME   SysTime;
  NMCOLUMNINFO Column[];
} NMEVENTDATA, *PNMEVENTDATA;