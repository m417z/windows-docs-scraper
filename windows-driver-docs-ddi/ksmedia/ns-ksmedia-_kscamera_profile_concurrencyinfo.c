typedef struct _KSCAMERA_PROFILE_CONCURRENCYINFO {
  GUID                   ReferenceGuid;
  UINT32                 Reserved;
  UINT32                 ProfileCount;
  PKSCAMERA_PROFILE_INFO Profiles;
} KSCAMERA_PROFILE_CONCURRENCYINFO, *PKSCAMERA_PROFILE_CONCURRENCYINFO;