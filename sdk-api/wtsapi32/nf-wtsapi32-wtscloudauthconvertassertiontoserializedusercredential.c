BOOL WTSCloudAuthConvertAssertionToSerializedUserCredential(
  WTS_CLOUD_AUTH_HANDLE          cloudAuthHandle,
  PCSTR                          assertion,
  ULONG                          assertionLength,
  PCWSTR                         resourceId,
  WTS_SERIALIZED_USER_CREDENTIAL **userCredential
);