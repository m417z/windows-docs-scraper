HRESULT FormatRequestForSetInformation(
  [in]           IWDFIoRequest              *pRequest,
  [in]           WDF_FILE_INFORMATION_CLASS InformationClass,
  [in, optional] IWDFFile                   *pFile,
  [in, optional] IWDFMemory                 *pInformationMemory,
  [in, optional] PWDFMEMORY_OFFSET          pInformationMemoryOffset
);