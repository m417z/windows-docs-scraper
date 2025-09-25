typedef struct _RSVP_ADSPEC {
  QOS_OBJECT_HDR    ObjectHdr;
  AD_GENERAL_PARAMS GeneralParams;
  ULONG             NumberOfServices;
  CONTROL_SERVICE   Services[1];
} RSVP_ADSPEC, *LPRSVP_ADSPEC;