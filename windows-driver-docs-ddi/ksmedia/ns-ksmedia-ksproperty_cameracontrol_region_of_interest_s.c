typedef struct {
  RECT  FocusRect;
  BOOL  AutoFocusLock;
  BOOL  AutoExposureLock;
  BOOL  AutoWhitebalanceLock;
  union {
    ULONG Capabilities;
    ULONG Configuration;
  };
} KSPROPERTY_CAMERACONTROL_REGION_OF_INTEREST_S, *PKSPROPERTY_CAMERACONTROL_REGION_OF_INTEREST_S;