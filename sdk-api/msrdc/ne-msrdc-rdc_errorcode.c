typedef enum __MIDL___MIDL_itf_msrdc_0000_0000_0001 {
  RDC_NoError = 0,
  RDC_HeaderVersionNewer,
  RDC_HeaderVersionOlder,
  RDC_HeaderMissingOrCorrupt,
  RDC_HeaderWrongType,
  RDC_DataMissingOrCorrupt,
  RDC_DataTooManyRecords,
  RDC_FileChecksumMismatch,
  RDC_ApplicationError,
  RDC_Aborted,
  RDC_Win32Error
} RDC_ErrorCode;