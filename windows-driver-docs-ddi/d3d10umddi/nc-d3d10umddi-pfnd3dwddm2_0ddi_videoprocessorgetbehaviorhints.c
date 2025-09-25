PFND3DWDDM2_0DDI_VIDEOPROCESSORGETBEHAVIORHINTS Pfnd3dwddm20DdiVideoprocessorgetbehaviorhints;

HRESULT Pfnd3dwddm20DdiVideoprocessorgetbehaviorhints(
  D3D10DDI_HDEVICE hDevice,
  D3D11_1DDI_HVIDEOPROCESSOR hVideoProcessor,
  UINT OutputWidth,
  UINT OutputHeight,
  DXGI_FORMAT OutputFormat,
  UINT StreamCount,
  const D3DWDDM2_0DDI_VIDEO_PROCESSOR_STREAM_BEHAVIOR_HINT *pStreams,
  UINT *pBehaviorHints
)
{...}