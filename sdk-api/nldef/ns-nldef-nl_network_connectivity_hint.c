typedef struct _NL_NETWORK_CONNECTIVITY_HINT {
  NL_NETWORK_CONNECTIVITY_LEVEL_HINT ConnectivityLevel;
  NL_NETWORK_CONNECTIVITY_COST_HINT  ConnectivityCost;
  BOOLEAN                            ApproachingDataLimit;
  BOOLEAN                            OverDataLimit;
  BOOLEAN                            Roaming;
} NL_NETWORK_CONNECTIVITY_HINT;