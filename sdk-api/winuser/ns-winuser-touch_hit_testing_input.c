typedef struct tagTOUCH_HIT_TESTING_INPUT {
  UINT32 pointerId;
  POINT  point;
  RECT   boundingBox;
  RECT   nonOccludedBoundingBox;
  UINT32 orientation;
} TOUCH_HIT_TESTING_INPUT, *PTOUCH_HIT_TESTING_INPUT;