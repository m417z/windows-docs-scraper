PFND3DWDDM2_1DDI_VIDEOPROCESSORSETSTREAMHDRMETADATA Pfnd3dwddm21DdiVideoprocessorsetstreamhdrmetadata;

VOID Pfnd3dwddm21DdiVideoprocessorsetstreamhdrmetadata(
  D3D10DDI_HDEVICE hDevice,
  D3D11_1DDI_HVIDEOPROCESSOR hVideoProcessor,
  UINT StreamIndex,
  D3DDDI_HDR_METADATA_TYPE Type,
  UINT Size,
  const VOID *pMetaData
)
{...}