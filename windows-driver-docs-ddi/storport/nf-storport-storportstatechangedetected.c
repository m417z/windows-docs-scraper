ULONG StorPortStateChangeDetected(
  [in]           PVOID            HwDeviceExtension,
  [in]           ULONG            ChangedEntity,
  [in]           PSTOR_ADDRESS    Address,
  [in]           ULONG            Attributes,
  [in, optional] PHW_STATE_CHANGE HwStateChange,
  [in, optional] PVOID            HwStateChangeContext
);