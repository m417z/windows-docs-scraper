typedef struct tagMSIPATCHSEQUENCEINFOW {
  LPCWSTR          szPatchData;
  MSIPATCHDATATYPE ePatchDataType;
  DWORD            dwOrder;
  UINT             uStatus;
} MSIPATCHSEQUENCEINFOW, *PMSIPATCHSEQUENCEINFOW;