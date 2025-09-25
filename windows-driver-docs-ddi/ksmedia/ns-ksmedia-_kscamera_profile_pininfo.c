typedef struct _KSCAMERA_PROFILE_PININFO {
  GUID                        PinCategory;
  union {
    struct {
      USHORT PinIndex;
      USHORT ProfileSensorType;
    };
    UINT32 Reserved;
  };
  UINT32                      MediaInfoCount;
  PKSCAMERA_PROFILE_MEDIAINFO MediaInfos;
} KSCAMERA_PROFILE_PININFO, *PKSCAMERA_PROFILE_PININFO;