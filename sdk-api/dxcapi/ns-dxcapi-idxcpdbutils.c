struct IDxcPdbUtils : IUnknown {
  HRESULT Load(
    IDxcBlob *pPdbOrDxil
  );
  HRESULT GetSourceCount(
    UINT32 *pCount
  );
  HRESULT GetSource(
    UINT32           uIndex,
    IDxcBlobEncoding **ppResult
  );
  HRESULT GetSourceName(
    UINT32 uIndex,
    BSTR   *pResult
  );
  HRESULT GetFlagCount(
    UINT32 *pCount
  );
  HRESULT GetFlag(
    UINT32 uIndex,
    BSTR   *pResult
  );
  HRESULT GetArgCount(
    UINT32 *pCount
  );
  HRESULT GetArg(
    UINT32 uIndex,
    BSTR   *pResult
  );
  HRESULT GetArgPairCount(
    UINT32 *pCount
  );
  HRESULT GetArgPair(
    UINT32 uIndex,
    BSTR   *pName,
    BSTR   *pValue
  );
  HRESULT GetDefineCount(
    UINT32 *pCount
  );
  HRESULT GetDefine(
    UINT32 uIndex,
    BSTR   *pResult
  );
  HRESULT GetTargetProfile(
    BSTR *pResult
  );
  HRESULT GetEntryPoint(
    BSTR *pResult
  );
  HRESULT GetMainFileName(
    BSTR *pResult
  );
  HRESULT GetHash(
    IDxcBlob **ppResult
  );
  HRESULT GetName(
    BSTR *pResult
  );
  BOOL    IsFullPDB();
  HRESULT GetFullPDB(
    IDxcBlob **ppFullPDB
  );
  HRESULT GetVersionInfo(
    IDxcVersionInfo **ppVersionInfo
  );
  HRESULT SetCompiler(
    IDxcCompiler3 *pCompiler
  );
  HRESULT CompileForFullPDB(
    IDxcResult **ppResult
  );
  HRESULT OverrideArgs(
    DxcArgPair *pArgPairs,
    UINT32     uNumArgPairs
  );
  HRESULT OverrideRootSignature(
    const WCHAR *pRootSignature
  );
};