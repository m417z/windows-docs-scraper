typedef struct _IMAGE_POLICY_METADATA {
  UCHAR              Version;
  UCHAR              Reserved0[7];
  ULONGLONG          ApplicationId;
  IMAGE_POLICY_ENTRY Policies[];
} IMAGE_POLICY_METADATA;