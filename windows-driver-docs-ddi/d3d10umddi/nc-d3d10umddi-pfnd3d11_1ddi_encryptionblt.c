PFND3D11_1DDI_ENCRYPTIONBLT Pfnd3d111DdiEncryptionblt;

VOID Pfnd3d111DdiEncryptionblt(
  D3D10DDI_HDEVICE hDevice,
  D3D11_1DDI_HCRYPTOSESSION hCryptoSession,
  D3D10DDI_HRESOURCE hSrcResource,
  D3D10DDI_HRESOURCE hDstResource,
  UINT IVSize,
  const VOID *pIV
)
{...}