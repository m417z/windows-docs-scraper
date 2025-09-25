typedef union _UCSI_SET_NOTIFICATION_ENABLE_COMMAND {
  UINT64 AsUInt64;
  struct {
    UINT8 Command;
    UINT8 DataLength;
    union {
      UINT16 NotificationEnable;
      struct {
        UINT16 CommandCompleteNotificationEnable : 1;
        UINT16 ExternalSupplyChangeNotificationEnable : 1;
        UINT16 PowerOperationModeChangeNotificationEnable : 1;
        UINT16 SupportedProviderCapabilitiesChangeNotificationEnable : 1;
        UINT16 NegotiatedPowerLevelChangeNotificationEnable : 1;
        UINT16 PdResetNotificationEnable : 1;
        UINT16 SupportedCamChangeNotificationEnable : 1;
        UINT16 BatteryChargingStatusChangeNotificationEnable : 1;
        UINT16 DataRoleSwapCompletedNotificationEnable : 1;
        UINT16 PowerRoleSwapCompletedNotificationEnable : 1;
        UINT16 ConnectChangeNotificationEnable : 1;
        UINT16 ErrorNotificationEnable : 1;
      };
    };
  };
} UCSI_SET_NOTIFICATION_ENABLE_COMMAND, *PUCSI_SET_NOTIFICATION_ENABLE_COMMAND;