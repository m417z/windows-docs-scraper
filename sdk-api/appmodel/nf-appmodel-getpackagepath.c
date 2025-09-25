LONG GetPackagePath(
  [in]            const PACKAGE_ID *packageId,
                  const UINT32     reserved,
  [in, out]       UINT32           *pathLength,
  [out, optional] PWSTR            path
);