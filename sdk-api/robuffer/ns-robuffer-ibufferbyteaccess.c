struct IBufferByteAccess : IUnknown {
  HRESULT Buffer(
    byte **value
  );
};