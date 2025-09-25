BOOL EcGetObjectArrayProperty(
  [in]  EC_OBJECT_ARRAY_PROPERTY_HANDLE ObjectArray,
  [in]  EC_SUBSCRIPTION_PROPERTY_ID     PropertyId,
  [in]  DWORD                           ArrayIndex,
  [in]  DWORD                           Flags,
  [in]  DWORD                           PropertyValueBufferSize,
  [in]  PEC_VARIANT                     PropertyValueBuffer,
  [out] PDWORD                          PropertyValueBufferUsed
);