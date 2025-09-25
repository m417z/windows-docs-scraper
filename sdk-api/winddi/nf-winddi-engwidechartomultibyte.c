ENGAPI INT EngWideCharToMultiByte(
  [in]            UINT   CodePage,
  [in, optional]  LPWSTR WideCharString,
  [in]            INT    BytesInWideCharString,
  [out, optional] LPSTR  MultiByteString,
  [in]            INT    BytesInMultiByteString
);