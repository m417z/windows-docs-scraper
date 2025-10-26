BOOL WINAPI WTSCloudAuthNetworkLogonWithSerializedCredential(
    [in]  WTS_CLOUD_AUTH_HANDLE cloudAuthHandle,
    [in]  WTS_SERIALIZED_USER_CREDENTIAL* userCredential,
    [out] HANDLE* tokenHandle
);