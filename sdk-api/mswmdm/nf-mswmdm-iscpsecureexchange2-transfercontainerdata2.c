HRESULT TransferContainerData2(
  [in]      BYTE           *pData,
  [in]      DWORD          dwSize,
  [in]      IWMDMProgress3 *pProgressCallback,
  [out]     UINT           *pfuReadyFlags,
  [in, out] BYTE [8]       abMac
);