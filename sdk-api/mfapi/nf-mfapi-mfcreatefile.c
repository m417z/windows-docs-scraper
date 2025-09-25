HRESULT MFCreateFile(
  MF_FILE_ACCESSMODE AccessMode,
  MF_FILE_OPENMODE   OpenMode,
  MF_FILE_FLAGS      fFlags,
  LPCWSTR            pwszFileURL,
  IMFByteStream      **ppIByteStream
);