typedef struct tagPOINTER_TOUCH_INFO {
  POINTER_INFO pointerInfo;
  TOUCH_FLAGS  touchFlags;
  TOUCH_MASK   touchMask;
  RECT         rcContact;
  RECT         rcContactRaw;
  UINT32       orientation;
  UINT32       pressure;
} POINTER_TOUCH_INFO;