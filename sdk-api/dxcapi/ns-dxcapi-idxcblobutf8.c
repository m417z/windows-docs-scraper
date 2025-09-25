struct IDxcBlobUtf8 : IDxcBlobEncoding {
  LPCSTR GetStringPointer();
  SIZE_T GetStringLength();
};