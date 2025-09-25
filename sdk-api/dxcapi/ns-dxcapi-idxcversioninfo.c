struct IDxcVersionInfo : IUnknown {
  HRESULT GetVersion(
    UINT32 *pMajor,
    UINT32 *pMinor
  );
  HRESULT GetFlags(
    UINT32 *pFlags
  );
};