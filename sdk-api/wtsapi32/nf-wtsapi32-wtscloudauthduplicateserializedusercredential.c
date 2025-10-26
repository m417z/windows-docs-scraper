BOOL WINAPI WTSCloudAuthDuplicateSerializedUserCredential(
  [in] const WTS_SERIALIZED_USER_CREDENTIAL* userCredential,
  [out] WTS_SERIALIZED_USER_CREDENTIAL** duplicatedUserCredential
);