PFND3D11_1DDI_QUERYAUTHENTICATEDCHANNEL Pfnd3d111DdiQueryauthenticatedchannel;

HRESULT Pfnd3d111DdiQueryauthenticatedchannel(
  D3D10DDI_HDEVICE hDevice,
  D3D11_1DDI_HAUTHCHANNEL hCAuthChannel,
  UINT InputDataSize,
  const VOID *pInputData,
  UINT OutputDataSize,
  VOID *pOutputData
)
{...}