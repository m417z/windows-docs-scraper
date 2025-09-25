typedef struct tagSTATDATA {
  FORMATETC   formatetc;
  DWORD       advf;
  IAdviseSink *pAdvSink;
  DWORD       dwConnection;
} STATDATA;