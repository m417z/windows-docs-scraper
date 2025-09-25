NS_OSVERSIONCHECK NsOsversioncheck;

BOOL NsOsversioncheck(
  [in] UINT CIMOSType,
  [in] UINT CIMOSProductSuite,
  [in] LPCWSTR CIMOSVersion,
  [in] LPCWSTR CIMOSBuildNumber,
  [in] LPCWSTR CIMServicePackMajorVersion,
  [in] LPCWSTR CIMServicePackMinorVersion,
       UINT uiReserved,
  [in] DWORD dwReserved
)
{...}