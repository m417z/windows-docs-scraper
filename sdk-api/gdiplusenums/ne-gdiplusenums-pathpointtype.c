typedef enum PathPointType {
  PathPointTypeStart = 0,
  PathPointTypeLine = 1,
  PathPointTypeBezier = 3,
  PathPointTypePathTypeMask = 0x07,
  PathPointTypeDashMode = 0x10,
  PathPointTypePathMarker = 0x20,
  PathPointTypeCloseSubpath = 0x80,
  PathPointTypeBezier3 = 3
} ;