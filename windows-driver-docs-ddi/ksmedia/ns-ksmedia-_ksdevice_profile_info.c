typedef struct _KSDEVICE_PROFILE_INFO {
  UINT32 Type;
  UINT32 Size;
  union {
    struct {
      KSCAMERA_PROFILE_INFO             Info;
      UINT32                            Reserved;
      UINT32                            ConcurrencyCount;
      PKSCAMERA_PROFILE_CONCURRENCYINFO Concurrency;
    } Camera;
  };
} KSDEVICE_PROFILE_INFO, *PKSDEVICE_PROFILE_INFO;