typedef struct peer_invitation_tag {
  GUID      applicationId;
  PEER_DATA applicationData;
  PWSTR     pwzMessage;
} PEER_INVITATION, *PPEER_INVITATION;