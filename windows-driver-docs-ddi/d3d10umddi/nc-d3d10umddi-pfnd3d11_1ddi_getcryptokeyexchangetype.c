PFND3D11_1DDI_GETCRYPTOKEYEXCHANGETYPE Pfnd3d111DdiGetcryptokeyexchangetype;

HRESULT Pfnd3d111DdiGetcryptokeyexchangetype(
  D3D10DDI_HDEVICE hDevice,
  const GUID *pCryptoType,
  const GUID *pDecodeProfile,
  UINT Index,
  GUID *pKeyExchangeType
)
{...}