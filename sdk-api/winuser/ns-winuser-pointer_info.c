typedef struct tagPOINTER_INFO {
  POINTER_INPUT_TYPE         pointerType;
  UINT32                     pointerId;
  UINT32                     frameId;
  POINTER_FLAGS              pointerFlags;
  HANDLE                     sourceDevice;
  HWND                       hwndTarget;
  POINT                      ptPixelLocation;
  POINT                      ptHimetricLocation;
  POINT                      ptPixelLocationRaw;
  POINT                      ptHimetricLocationRaw;
  DWORD                      dwTime;
  UINT32                     historyCount;
  INT32                      InputData;
  DWORD                      dwKeyStates;
  UINT64                     PerformanceCount;
  POINTER_BUTTON_CHANGE_TYPE ButtonChangeType;
} POINTER_INFO;