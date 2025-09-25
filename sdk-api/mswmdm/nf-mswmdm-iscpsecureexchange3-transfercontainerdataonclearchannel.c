HRESULT TransferContainerDataOnClearChannel(
  IMDSPDevice    *pDevice,
  BYTE           *pData,
  DWORD          dwSize,
  IWMDMProgress3 *pProgressCallback,
  UINT           *pfuReadyFlags
);