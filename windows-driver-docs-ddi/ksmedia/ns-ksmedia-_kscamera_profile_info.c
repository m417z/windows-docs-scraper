typedef struct _KSCAMERA_PROFILE_INFO {
  GUID                      ProfileId;
  UINT32                    Index;
  UINT32                    PinCount;
  PKSCAMERA_PROFILE_PININFO Pins;
} KSCAMERA_PROFILE_INFO, *PKSCAMERA_PROFILE_INFO;