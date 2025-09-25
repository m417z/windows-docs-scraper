typedef struct CLRES_V1_FUNCTIONS {
  POPEN_ROUTINE                  Open;
  PCLOSE_ROUTINE                 Close;
  PONLINE_ROUTINE                Online;
  POFFLINE_ROUTINE               Offline;
  PTERMINATE_ROUTINE             Terminate;
  PLOOKS_ALIVE_ROUTINE           LooksAlive;
  PIS_ALIVE_ROUTINE              IsAlive;
  PARBITRATE_ROUTINE             Arbitrate;
  PRELEASE_ROUTINE               Release;
  PRESOURCE_CONTROL_ROUTINE      ResourceControl;
  PRESOURCE_TYPE_CONTROL_ROUTINE ResourceTypeControl;
} CLRES_V1_FUNCTIONS, *PCLRES_V1_FUNCTIONS;