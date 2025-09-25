typedef struct _MSV1_0_SUBAUTH_RESPONSE {
  MSV1_0_PROTOCOL_MESSAGE_TYPE MessageType;
  ULONG                        SubAuthInfoLength;
  PUCHAR                       SubAuthReturnBuffer;
} MSV1_0_SUBAUTH_RESPONSE, *PMSV1_0_SUBAUTH_RESPONSE;