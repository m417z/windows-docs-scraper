int WSPStartup(
  [in]  WORD                wVersionRequested,
  [out] LPWSPDATA           lpWSPData,
  [in]  LPWSAPROTOCOL_INFOW lpProtocolInfo,
  [in]  WSPUPCALLTABLE      UpcallTable,
  [out] LPWSPPROC_TABLE     lpProcTable
);