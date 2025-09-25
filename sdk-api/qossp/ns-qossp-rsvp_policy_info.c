typedef struct _RSVP_POLICY_INFO {
  QOS_OBJECT_HDR ObjectHdr;
  ULONG          NumPolicyElement;
  RSVP_POLICY    PolicyElement[1];
} RSVP_POLICY_INFO, *LPRSVP_POLICY_INFO;