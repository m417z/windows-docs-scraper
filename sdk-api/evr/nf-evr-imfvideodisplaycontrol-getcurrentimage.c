HRESULT GetCurrentImage(
  [in, out] BITMAPINFOHEADER *pBih,
  [out]     BYTE             **pDib,
  [out]     DWORD            *pcbDib,
  [in, out] LONGLONG         *pTimeStamp
);