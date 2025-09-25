typedef struct _EAP_ERROR {
  DWORD           dwWinError;
  EAP_METHOD_TYPE type;
  DWORD           dwReasonCode;
  GUID            rootCauseGuid;
  GUID            repairGuid;
  GUID            helpLinkGuid;
  LPWSTR          pRootCauseString;
  LPWSTR          pRepairString;
} EAP_ERROR;