typedef struct tagMSIPATCHSEQUENCEINFOA {
  LPCSTR           szPatchData;
  MSIPATCHDATATYPE ePatchDataType;
  DWORD            dwOrder;
  UINT             uStatus;
} MSIPATCHSEQUENCEINFOA, *PMSIPATCHSEQUENCEINFOA;