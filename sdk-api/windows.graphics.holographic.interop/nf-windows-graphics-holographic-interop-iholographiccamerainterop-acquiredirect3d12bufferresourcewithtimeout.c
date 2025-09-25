HRESULT AcquireDirect3D12BufferResourceWithTimeout(
  ID3D12Resource     *pResourceToAcquire,
  ID3D12CommandQueue *pCommandQueue,
  UINT64             duration
);