struct IDxcUtils : IUnknown {
  HRESULT CreateBlobFromBlob(
    IDxcBlob *pBlob,
    UINT32   offset,
    UINT32   length,
    IDxcBlob **ppResult
  );
  HRESULT CreateBlobFromPinned(
    LPCVOID          pData,
    UINT32           size,
    UINT32           codePage,
    IDxcBlobEncoding **ppBlobEncoding
  );
  HRESULT MoveToBlob(
    LPCVOID          pData,
    IMalloc          *pIMalloc,
    UINT32           size,
    UINT32           codePage,
    IDxcBlobEncoding **ppBlobEncoding
  );
  HRESULT CreateBlob(
    LPCVOID          pData,
    UINT32           size,
    UINT32           codePage,
    IDxcBlobEncoding **ppBlobEncoding
  );
  HRESULT LoadFile(
    LPCWSTR          pFileName,
    UINT32           *pCodePage,
    IDxcBlobEncoding **ppBlobEncoding
  );
  HRESULT CreateReadOnlyStreamFromBlob(
    IDxcBlob *pBlob,
    IStream  **ppStream
  );
  HRESULT CreateDefaultIncludeHandler(
    IDxcIncludeHandler **ppResult
  );
  HRESULT GetBlobAsUtf8(
    IDxcBlob     *pBlob,
    IDxcBlobUtf8 **ppBlobEncoding
  );
  HRESULT GetBlobAsWide(
    IDxcBlob     *pBlob,
    IDxcBlobWide **ppBlobEncoding
  );
  HRESULT GetBlobAsUtf16(
    IDxcBlob     *pBlob,
    IDxcBlobWide **ppBlobEncoding
  );
  HRESULT GetDxilContainerPart(
    const DxcBuffer *pShader,
    UINT32          DxcPart,
    void            **ppPartData,
    UINT32          *pPartSizeInBytes
  );
  HRESULT CreateReflection(
    const DxcBuffer *pData,
    REFIID          iid,
    void            **ppvReflection
  );
  HRESULT BuildArguments(
    LPCWSTR          pSourceName,
    LPCWSTR          pEntryPoint,
    LPCWSTR          pTargetProfile,
    LPCWSTR          *pArguments,
    UINT32           argCount,
    const DxcDefine  *pDefines,
    UINT32           defineCount,
    IDxcCompilerArgs **ppArgs
  );
  HRESULT GetPDBContents(
    IDxcBlob *pPDBBlob,
    IDxcBlob **ppHash,
    IDxcBlob **ppContainer
  );
};