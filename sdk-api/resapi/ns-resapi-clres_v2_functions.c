typedef struct CLRES_V2_FUNCTIONS {
  POPEN_V2_ROUTINE               Open;
  PCLOSE_ROUTINE                 Close;
  PONLINE_V2_ROUTINE             Online;
  POFFLINE_V2_ROUTINE            Offline;
  PTERMINATE_ROUTINE             Terminate;
  PLOOKS_ALIVE_ROUTINE           LooksAlive;
  PIS_ALIVE_ROUTINE              IsAlive;
  PARBITRATE_ROUTINE             Arbitrate;
  PRELEASE_ROUTINE               Release;
  PRESOURCE_CONTROL_ROUTINE      ResourceControl;
  PRESOURCE_TYPE_CONTROL_ROUTINE ResourceTypeControl;
  PCANCEL_ROUTINE                Cancel;
} CLRES_V2_FUNCTIONS, *PCLRES_V2_FUNCTIONS;