struct IDxcResult : IDxcOperationResult {
  BOOL         HasOutput(
    DXC_OUT_KIND dxcOutKind
  );
  HRESULT      GetOutput(
    DXC_OUT_KIND dxcOutKind,
    REFIID       iid,
    void         **ppvObject,
    IDxcBlobWide **ppOutputName
  );
  UINT32       GetNumOutputs();
  DXC_OUT_KIND GetOutputByIndex(
    UINT32 Index
  );
  DXC_OUT_KIND PrimaryOutput();
};