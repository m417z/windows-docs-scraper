HRESULT InitializeEx(
  [in] VSS_ID                     WriterId,
  [in] LPCWSTR                    wszWriterName,
  [in] DWORD                      dwMajorVersion,
  [in] DWORD                      dwMinorVersion,
  [in] VSS_USAGE_TYPE             ut,
  [in] VSS_SOURCE_TYPE            st,
  [in] VSS_APPLICATION_LEVEL      nLevel,
  [in] DWORD                      dwTimeoutFreeze,
  [in] VSS_ALTERNATE_WRITER_STATE aws,
  [in] bool                       bIOThrottlingOnly,
  [in] LPCWSTR                    wszWriterInstanceName
);