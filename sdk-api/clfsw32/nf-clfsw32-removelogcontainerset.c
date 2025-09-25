CLFSUSER_API BOOL RemoveLogContainerSet(
  [in]                HANDLE hLog,
  [in]                USHORT cContainer,
  [in]                LPWSTR *rgwszContainerPath,
  [in]                BOOL   fForce,
  [in, out, optional] LPVOID pReserved
);