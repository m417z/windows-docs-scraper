NTSTATUS GetDeviceAttributeSteppings(
  [in]  ULONG                     ulNodeId,
  [in]  eChannelTargetType        targetType,
  [out] PKSPROPERTY_STEPPING_LONG pKsPropStepLong,
  [in]  UINT32                    ui32DataSize
);