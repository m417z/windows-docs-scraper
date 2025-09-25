typedef struct _CROSS_CERT_DIST_POINTS_INFO {
  DWORD               dwSyncDeltaTime;
  DWORD               cDistPoint;
  PCERT_ALT_NAME_INFO rgDistPoint;
} CROSS_CERT_DIST_POINTS_INFO, *PCROSS_CERT_DIST_POINTS_INFO;