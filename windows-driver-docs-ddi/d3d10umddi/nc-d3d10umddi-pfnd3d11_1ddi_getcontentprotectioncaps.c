PFND3D11_1DDI_GETCONTENTPROTECTIONCAPS Pfnd3d111DdiGetcontentprotectioncaps;

HRESULT Pfnd3d111DdiGetcontentprotectioncaps(
  D3D10DDI_HDEVICE hDevice,
  const GUID *pCryptoType,
  const GUID *pDecodeProfile,
  D3D11_1DDI_VIDEO_CONTENT_PROTECTION_CAPS *pCaps
)
{...}