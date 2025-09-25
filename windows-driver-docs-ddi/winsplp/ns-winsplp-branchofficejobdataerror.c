typedef struct {
  DWORD    LastError;
  LPWSTR   pDocumentName;
  LPWSTR   pUserName;
  LPWSTR   pPrinterName;
  LPWSTR   pDataType;
  LONGLONG TotalSize;
  LONGLONG PrintedSize;
  DWORD    TotalPages;
  DWORD    PrintedPages;
  LPWSTR   pMachineName;
  LPWSTR   pJobError;
  LPWSTR   pErrorDescription;
} BranchOfficeJobDataError, *PBranchOfficeJobDataError;