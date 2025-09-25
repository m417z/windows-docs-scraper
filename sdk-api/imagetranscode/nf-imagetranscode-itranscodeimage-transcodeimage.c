HRESULT TranscodeImage(
  [in]            IShellItem *pShellItem,
                  UINT       uiMaxWidth,
                  UINT       uiMaxHeight,
                  DWORD      flags,
                  IStream    *pvImage,
  [out, optional] UINT       *puiWidth,
  [out, optional] UINT       *puiHeight
);