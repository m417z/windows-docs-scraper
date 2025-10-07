typedef struct _PRINTER_NOTIFY_OPTIONS {
  DWORD                        Version;
  DWORD                        Flags;
  DWORD                        Count;
  PPRINTER_NOTIFY_OPTIONS_TYPE pTypes;
} PRINTER_NOTIFY_OPTIONS, *PPRINTER_NOTIFY_OPTIONS;