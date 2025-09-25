PFND3DWDDM2_0DDI_VIDEODECODERENABLEDOWNSAMPLING Pfnd3dwddm20DdiVideodecoderenabledownsampling;

HRESULT Pfnd3dwddm20DdiVideodecoderenabledownsampling(
  D3D10DDI_HDEVICE hDevice,
  D3D11_1DDI_HDECODE hDecoder,
  D3DDDI_COLOR_SPACE_TYPE InputColorSpace,
  const D3D11_1DDI_VIDEO_DECODER_DESC *pOutputDesc,
  D3DDDI_COLOR_SPACE_TYPE OutputColorSpace,
  UINT ReferenceFrameCount
)
{...}