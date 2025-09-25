SECURITY_STATUS NCryptStreamUpdate(
  [in] NCRYPT_STREAM_HANDLE hStream,
  [in] const BYTE           *pbData,
       SIZE_T               cbData,
       BOOL                 fFinal
);