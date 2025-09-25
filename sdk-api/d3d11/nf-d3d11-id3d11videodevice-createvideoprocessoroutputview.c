HRESULT CreateVideoProcessorOutputView(
  [in]  ID3D11Resource                               *pResource,
  [in]  ID3D11VideoProcessorEnumerator               *pEnum,
  [in]  const D3D11_VIDEO_PROCESSOR_OUTPUT_VIEW_DESC *pDesc,
  [out] ID3D11VideoProcessorOutputView               **ppVPOView
);