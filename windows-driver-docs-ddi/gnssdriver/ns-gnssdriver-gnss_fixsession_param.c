typedef struct {
  ULONG               Size;
  ULONG               Version;
  ULONG               FixSessionID;
  GNSS_FIXSESSIONTYPE SessionType;
  ULONG               HorizontalAccuracy;
  ULONG               HorizontalConfidence;
  ULONG               Reserved[9];
  ULONG               FixLevelOfDetails;
  union {
    GNSS_SINGLESHOT_PARAM         SingleShotParam;
    GNSS_DISTANCETRACKING_PARAM   DistanceParam;
    GNSS_CONTINUOUSTRACKING_PARAM ContinuousParam;
    GNSS_LKGFIX_PARAM             LkgFixParam;
    BYTE                          UnusedParam[268];
  };
  BYTE                Unused[256];
} GNSS_FIXSESSION_PARAM, *PGNSS_FIXSESSION_PARAM;