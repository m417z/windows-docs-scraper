BOOL WINAPI WTSCloudAuthConvertAssertionToSerializedUserCredential(
  [in] WTS_CLOUD_AUTH_HANDLE cloudAuthHandle,
  [in] reads_bytes_(assertionLength) PCSTR assertion,
  [in] ULONG assertionLength,
  [in] z_ PCWSTR resourceId,
  [out] WTS_SERIALIZED_USER_CREDENTIAL** userCredential
);