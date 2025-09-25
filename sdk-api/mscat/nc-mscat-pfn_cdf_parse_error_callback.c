PFN_CDF_PARSE_ERROR_CALLBACK PfnCdfParseErrorCallback;

void PfnCdfParseErrorCallback(
  [in] DWORD dwErrorArea,
  [in] DWORD dwLocalError,
  [in] WCHAR *pwszLine
)
{...}