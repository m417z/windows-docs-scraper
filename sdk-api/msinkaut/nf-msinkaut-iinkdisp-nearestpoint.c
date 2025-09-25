HRESULT NearestPoint(
  [in]                long           X,
  [in]                long           Y,
  [in, out, optional] float          *PointOnStroke,
  [in, out, optional] float          *DistanceFromPacket,
  [out, retval]       IInkStrokeDisp **Stroke
);