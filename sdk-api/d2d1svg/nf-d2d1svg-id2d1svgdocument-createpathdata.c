HRESULT CreatePathData(
  [in, optional] const FLOAT                 *segmentData,
                 UINT32                      segmentDataCount,
  [in, optional] const D2D1_SVG_PATH_COMMAND *commands,
                 UINT32                      commandsCount,
  [out]          ID2D1SvgPathData            **pathData
);