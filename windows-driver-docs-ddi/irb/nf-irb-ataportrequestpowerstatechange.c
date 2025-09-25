VOID AtaPortRequestPowerStateChange(
  PVOID           ChannelExtension,
  UCHAR           TargetId,
  UCHAR           Lun,
  IDE_POWER_STATE DesiredPowerState
);