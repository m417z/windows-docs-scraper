PFND3DWDDM2_0DDI_GETDATAFORNEWHARDWAREKEY Pfnd3dwddm20DdiGetdatafornewhardwarekey;

HRESULT Pfnd3dwddm20DdiGetdatafornewhardwarekey(
  D3D10DDI_HDEVICE hDevice,
  D3D11_1DDI_HCRYPTOSESSION hCryptoSession,
  UINT PrivateInputSize,
  const void *pPrivatInputData,
  UINT64 *pPrivateOutputData
)
{...}