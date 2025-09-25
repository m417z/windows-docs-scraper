typedef struct {
  ISCSI_SECURITY_FLAGS            SecurityFlags;
  IKE_IDENTIFICATION_PAYLOAD_TYPE IdType;
  ULONG                           IdLengthInBytes;
  PUCHAR                          Id;
  ULONG                           KeyLengthInBytes;
  PUCHAR                          Key;
} IKE_AUTHENTICATION_PRESHARED_KEY, *PIKE_AUTHENTICATION_PRESHARED_KEY;