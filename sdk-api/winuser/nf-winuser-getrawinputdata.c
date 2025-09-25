UINT GetRawInputData(
  [in]            HRAWINPUT hRawInput,
  [in]            UINT      uiCommand,
  [out, optional] LPVOID    pData,
  [in, out]       PUINT     pcbSize,
  [in]            UINT      cbSizeHeader
);