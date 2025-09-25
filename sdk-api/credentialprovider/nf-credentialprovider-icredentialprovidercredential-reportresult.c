HRESULT ReportResult(
  [in]  NTSTATUS                        ntsStatus,
  [in]  NTSTATUS                        ntsSubstatus,
  [out] LPWSTR                          *ppszOptionalStatusText,
  [out] CREDENTIAL_PROVIDER_STATUS_ICON *pcpsiOptionalStatusIcon
);