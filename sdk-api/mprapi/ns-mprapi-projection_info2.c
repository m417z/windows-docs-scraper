typedef struct _PROJECTION_INFO2 {
  UCHAR projectionInfoType;
  union {
    PPP_PROJECTION_INFO2   PppProjectionInfo;
    IKEV2_PROJECTION_INFO2 Ikev2ProjectionInfo;
  };
} PROJECTION_INFO2, *PPROJECTION_INFO2;