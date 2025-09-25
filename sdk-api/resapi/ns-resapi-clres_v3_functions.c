typedef struct CLRES_V3_FUNCTIONS {
  POPEN_V2_ROUTINE           Open;
  PCLOSE_ROUTINE             Close;
  PONLINE_V2_ROUTINE         Online;
  POFFLINE_V2_ROUTINE        Offline;
  PTERMINATE_ROUTINE         Terminate;
  PLOOKS_ALIVE_ROUTINE       LooksAlive;
  PIS_ALIVE_ROUTINE          IsAlive;
  PARBITRATE_ROUTINE         Arbitrate;
  PRELEASE_ROUTINE           Release;
  PBEGIN_RESCALL_ROUTINE     BeginResourceControl;
  PBEGIN_RESTYPECALL_ROUTINE BeginResourceTypeControl;
  PCANCEL_ROUTINE            Cancel;
} CLRES_V3_FUNCTIONS, *PCLRES_V3_FUNCTIONS;