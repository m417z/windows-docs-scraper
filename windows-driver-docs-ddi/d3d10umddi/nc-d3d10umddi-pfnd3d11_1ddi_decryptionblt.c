PFND3D11_1DDI_DECRYPTIONBLT Pfnd3d111DdiDecryptionblt;

VOID Pfnd3d111DdiDecryptionblt(
  D3D10DDI_HDEVICE hDevice,
  D3D11_1DDI_HCRYPTOSESSION hCryptoSession,
  D3D10DDI_HRESOURCE hSrcResource,
  D3D10DDI_HRESOURCE hDstResource,
  const D3D11_1DDI_ENCRYPTED_BLOCK_INFO *pEncryptedBlockInfo,
  UINT ContentKeySize,
  const VOID *pContentKey,
  UINT IVSize,
  const VOID *pIV
)
{...}