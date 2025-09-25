struct IDxcBlob : IUnknown {
  LPVOID GetBufferPointer();
  SIZE_T GetBufferSize();
};