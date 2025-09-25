CLFSUSER_API BOOL AddLogContainerSet(
  [in]                HANDLE     hLog,
  [in]                USHORT     cContainer,
  [in, optional]      PULONGLONG pcbContainer,
  [in]                LPWSTR     *rgwszContainerPath,
  [in, out, optional] LPVOID     pReserved
);