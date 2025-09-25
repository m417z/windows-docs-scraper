typedef struct peer_invitation_response_tag {
  PEER_INVITATION_RESPONSE_TYPE action;
  PWSTR                         pwzMessage;
  HRESULT                       hrExtendedInfo;
} PEER_INVITATION_RESPONSE, *PPEER_INVITATION_RESPONSE;