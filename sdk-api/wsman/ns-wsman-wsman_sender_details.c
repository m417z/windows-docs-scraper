typedef struct _WSMAN_SENDER_DETAILS {
  PCWSTR                    senderName;
  PCWSTR                    authenticationMechanism;
  WSMAN_CERTIFICATE_DETAILS *certificateDetails;
  HANDLE                    clientToken;
  PCWSTR                    httpURL;
} WSMAN_SENDER_DETAILS;