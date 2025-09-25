typedef struct _MSV1_0_SUBAUTH_REQUEST {
  MSV1_0_PROTOCOL_MESSAGE_TYPE MessageType;
  ULONG                        SubAuthPackageId;
  ULONG                        SubAuthInfoLength;
  PUCHAR                       SubAuthSubmitBuffer;
} MSV1_0_SUBAUTH_REQUEST, *PMSV1_0_SUBAUTH_REQUEST;