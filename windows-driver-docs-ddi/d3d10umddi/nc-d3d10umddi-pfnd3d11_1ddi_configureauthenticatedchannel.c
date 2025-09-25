PFND3D11_1DDI_CONFIGUREAUTHENTICATEDCHANNEL Pfnd3d111DdiConfigureauthenticatedchannel;

HRESULT Pfnd3d111DdiConfigureauthenticatedchannel(
  D3D10DDI_HDEVICE hDevice,
  D3D11_1DDI_HAUTHCHANNEL hCAuthChannel,
  UINT InputDataSize,
  const VOID *pInputData,
  D3D11_1DDI_AUTHENTICATED_CONFIGURE_OUTPUT *pOutputData
)
{...}