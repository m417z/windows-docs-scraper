typedef struct _RSVP_STATUS_INFO {
  QOS_OBJECT_HDR ObjectHdr;
  ULONG          StatusCode;
  ULONG          ExtendedStatus1;
  ULONG          ExtendedStatus2;
} RSVP_STATUS_INFO, *LPRSVP_STATUS_INFO;