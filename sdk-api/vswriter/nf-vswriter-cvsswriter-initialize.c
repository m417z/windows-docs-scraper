HRESULT Initialize(
  [in] VSS_ID                     WriterId,
  [in] LPCWSTR                    wszWriterName,
  [in] VSS_USAGE_TYPE             ut,
  [in] VSS_SOURCE_TYPE            st,
  [in] VSS_APPLICATION_LEVEL      nLevel,
  [in] DWORD                      dwTimeoutFreeze,
  [in] VSS_ALTERNATE_WRITER_STATE aws,
  [in] bool                       bIOThrottlingOnly,
  [in] LPCWSTR                    wszWriterInstanceName
);