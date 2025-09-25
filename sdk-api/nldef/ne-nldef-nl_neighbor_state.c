typedef enum _NL_NEIGHBOR_STATE {
  NlnsUnreachable,
  NlnsIncomplete,
  NlnsProbe,
  NlnsDelay,
  NlnsStale,
  NlnsReachable,
  NlnsPermanent,
  NlnsMaximum
} NL_NEIGHBOR_STATE, *PNL_NEIGHBOR_STATE;