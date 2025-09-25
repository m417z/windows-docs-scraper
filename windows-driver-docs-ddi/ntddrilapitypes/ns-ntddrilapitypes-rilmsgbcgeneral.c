typedef struct RILMSGBCGENERAL {
  RILGEOSCOPE                dwGeoScope;
  DWORD                      dwMsgCode;
  DWORD                      dwUpdateNumber;
  DWORD                      dwID;
  DWORD                      dwSerialNumber;
  RILMSGDCS                  rmdDataCoding;
  DWORD                      dwTotalPages;
  DWORD                      dwPageNumber;
  RILMSGBCGENERALWARNINGTYPE dwWarningType;
  BOOL                       bEmergencyUserAlert;
  BOOL                       bMessagePopup;
  RILSYSTEMTIME              stSCReceiveTime;
  BYTE                       digSig[43];
  DWORD                      cchMsgLength;
  BYTE                       rgbMsg[512];
} RILMSGBCGENERAL, *LPRILMSGBCGENERAL;