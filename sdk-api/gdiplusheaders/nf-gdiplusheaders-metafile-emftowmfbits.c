UINT EmfToWmfBits(
  [in]           HENHMETAFILE hemf,
  [in]           UINT         cbData16,
  [out]          LPBYTE       pData16,
  [in, optional] INT          iMapMode,
  [in, optional] INT          eFlags
);