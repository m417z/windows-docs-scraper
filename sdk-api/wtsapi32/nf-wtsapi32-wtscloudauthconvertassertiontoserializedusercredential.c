BOOL WTSCloudAuthConvertAssertionToSerializedUserCredential(
  [in]  WTS_CLOUD_AUTH_HANDLE          cloudAuthHandle,
  [in]  PCSTR                          assertion,
  [in]  ULONG                          assertionLength,
  [in]  PCWSTR                         resourceId,
  [out] WTS_SERIALIZED_USER_CREDENTIAL **userCredential
);