DWORD DuplicateEncryptionInfoFile(
  [in]           LPCWSTR                     SrcFileName,
  [in]           LPCWSTR                     DstFileName,
  [in]           DWORD                       dwCreationDistribution,
  [in]           DWORD                       dwAttributes,
  [in, optional] const LPSECURITY_ATTRIBUTES lpSecurityAttributes
);