BOOL WTSCloudAuthNetworkLogonWithSerializedCredential(
  WTS_CLOUD_AUTH_HANDLE          cloudAuthHandle,
  WTS_SERIALIZED_USER_CREDENTIAL *userCredential,
  HANDLE                         *token
);