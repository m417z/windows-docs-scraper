typedef struct _PROJECTION_INFO {
  UCHAR projectionInfoType;
  union {
    PPP_PROJECTION_INFO   PppProjectionInfo;
    IKEV2_PROJECTION_INFO Ikev2ProjectionInfo;
  };
} PROJECTION_INFO, *PPROJECTION_INFO;