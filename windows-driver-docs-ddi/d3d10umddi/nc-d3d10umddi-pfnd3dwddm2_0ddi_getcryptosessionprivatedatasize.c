PFND3DWDDM2_0DDI_GETCRYPTOSESSIONPRIVATEDATASIZE Pfnd3dwddm20DdiGetcryptosessionprivatedatasize;

void Pfnd3dwddm20DdiGetcryptosessionprivatedatasize(
  D3D10DDI_HDEVICE hDevice,
  const GUID *pCryptoType,
  const GUID *pDecoderProfile,
  const GUID *pKeyExchangeType,
  UINT *pPrivateInputSize,
  UINT *pPrivateOutputSize
)
{...}