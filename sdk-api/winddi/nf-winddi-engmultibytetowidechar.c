ENGAPI INT EngMultiByteToWideChar(
  [in]            UINT   CodePage,
  [out, optional] LPWSTR WideCharString,
  [in]            INT    BytesInWideCharString,
  [in, optional]  LPSTR  MultiByteString,
  [in]            INT    BytesInMultiByteString
);