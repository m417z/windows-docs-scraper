typedef struct _ONEX_EAP_ERROR {
  DWORD              dwWinError;
  EAP_METHOD_TYPE    type;
  DWORD              dwReasonCode;
  GUID               rootCauseGuid;
  GUID               repairGuid;
  GUID               helpLinkGuid;
  DWORD              fRootCauseString : 1;
  DWORD              fRepairString : 1;
  ONEX_VARIABLE_BLOB RootCauseString;
  ONEX_VARIABLE_BLOB RepairString;
} ONEX_EAP_ERROR, *PONEX_EAP_ERROR;