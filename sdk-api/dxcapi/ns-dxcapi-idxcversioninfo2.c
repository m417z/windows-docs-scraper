struct IDxcVersionInfo2 : IDxcVersionInfo {
  HRESULT GetCommitInfo(
    UINT32 *pCommitCount,
    char   **pCommitHash
  );
};