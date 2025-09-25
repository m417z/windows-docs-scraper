struct IDARG_OUT_QUERY_HWCURSOR2 {
  BOOL                    IsCursorVisible;
  INT                     X;
  INT                     Y;
  BOOL                    IsCursorShapeUpdated;
  IDDCX_CURSOR_SHAPE_INFO CursorShapeInfo;
  BOOL                    PositionValid;
  UINT                    PositionId;
};