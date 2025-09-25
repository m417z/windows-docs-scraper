typedef struct _KSCAMERA_PROFILE_MEDIAINFO {
  struct {
    UINT32 X;
    UINT32 Y;
  } Resolution;
  struct {
    UINT32 Numerator;
    UINT32 Denominator;
  } MaxFrameRate;
  ULONGLONG Flags;
  UINT32    Data0;
  UINT32    Data1;
  UINT32    Data2;
  UINT32    Data3;
} KSCAMERA_PROFILE_MEDIAINFO, *PKSCAMERA_PROFILE_MEDIAINFO;