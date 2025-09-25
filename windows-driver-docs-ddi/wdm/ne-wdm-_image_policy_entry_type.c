typedef enum _IMAGE_POLICY_ENTRY_TYPE {
  ImagePolicyEntryTypeNone,
  ImagePolicyEntryTypeBool,
  ImagePolicyEntryTypeInt8,
  ImagePolicyEntryTypeUInt8,
  ImagePolicyEntryTypeInt16,
  ImagePolicyEntryTypeUInt16,
  ImagePolicyEntryTypeInt32,
  ImagePolicyEntryTypeUInt32,
  ImagePolicyEntryTypeInt64,
  ImagePolicyEntryTypeUInt64,
  ImagePolicyEntryTypeAnsiString,
  ImagePolicyEntryTypeUnicodeString,
  ImagePolicyEntryTypeOverride,
  ImagePolicyEntryTypeMaximum
} IMAGE_POLICY_ENTRY_TYPE;