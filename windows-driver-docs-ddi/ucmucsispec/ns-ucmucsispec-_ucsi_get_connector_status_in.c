typedef struct _UCSI_GET_CONNECTOR_STATUS_IN {
  union {
    UINT16 AsUInt16;
    struct {
      UINT16 ExternalSupplyChange : 1;
      UINT16 PowerOperationModeChange : 1;
      UINT16 SupportedProviderCapabilitiesChange : 1;
      UINT16 NegotiatedPowerLevelChange : 1;
      UINT16 PdResetComplete : 1;
      UINT16 SupportedCamChange : 1;
      UINT16 BatteryChargingStatusChange : 1;
      UINT16 ConnectorPartnerChange : 1;
      UINT16 PowerDirectionChange : 1;
      UINT16 ConnectChange : 1;
      UINT16 Error : 1;
    };
  } ConnectorStatusChange;
  UINT16 PowerOperationMode : 3;
  UINT16 ConnectStatus : 1;
  UINT16 PowerDirection : 1;
  UINT16 ConnectorPartnerFlags : 8;
  UINT16 ConnectorPartnerType : 3;
  UINT32 RequestDataObject;
  union {
    struct {
      UINT8 BatteryChargingStatus : 2;
      UINT8 PowerBudgetLimitedReason : 4;
    };
    struct {
      UINT8 PowerBudgetLowered : 1;
      UINT8 ReachingPowerBudgetLimit : 1;
    } bmPowerBudgetLimitedReason;
  };
} UCSI_GET_CONNECTOR_STATUS_IN, *PUCSI_GET_CONNECTOR_STATUS_IN;