typedef union _USBC_PD_POWER_DATA_OBJECT {
  UINT32 U;
  struct {
    UINT32 Reserved : 30;
    UINT32 Type : 2;
  } Common;
  struct {
    UINT32 MaximumCurrentIn10mA : 10;
    UINT32 VoltageIn50mV : 10;
    UINT32 PeakCurrent : 2;
    UINT32 Reserved1 : 3;
    UINT32 DataRoleSwap : 1;
    UINT32 UsbCommunicationCapable : 1;
    UINT32 ExternallyPowered : 1;
    UINT32 UsbSuspendSupported : 1;
    UINT32 DualRolePower : 1;
    UINT32 FixedSupply : 2;
  } FixedSupplyPdo;
  struct {
    UINT32 MaximumAllowablePowerIn250mW : 10;
    UINT32 MinimumVoltageIn50mV : 10;
    UINT32 MaximumVoltageIn50mV : 10;
    UINT32 Battery : 2;
  } BatterySupplyPdo;
  struct {
    UINT32 MaximumCurrentIn10mA : 10;
    UINT32 MinimumVoltageIn50mV : 10;
    UINT32 MaximumVoltageIn50mV : 10;
    UINT32 VariableSupportNonBattery : 2;
  } VariableSupplyNonBatteryPdo;
  struct {
    UINT32 MaximumCurrentIn50mA : 7;
    UINT32 Reserved1 : 1;
    UINT32 MinimumVoltageIn100mV : 8;
    UINT32 Reserved2 : 1;
    UINT32 MaximumVoltageIn100mV : 8;
    UINT32 Reserved3 : 2;
    UINT32 PpsPowerLimited : 1;
    UINT32 AugmentedPowerDataObjectType : 2;
    UINT32 AugmentedPowerDataObject : 2;
  } ProgrammablePowerSupplyApdo;
  struct {
    UINT32 OperationalCurrentIn10mA : 10;
    UINT32 VoltageIn50mV : 10;
    UINT32 Reserved : 5;
    UINT32 DataRoleSwap : 1;
    UINT32 UsbCommunicationCapable : 1;
    UINT32 ExternallyPowered : 1;
    UINT32 HigherCapability : 1;
    UINT32 DualRolePower : 1;
    UINT32 FixedSupply : 2;
  } FixedSupplyPdoSink;
  struct {
    UINT32 OperationalPowerIn250mW : 10;
    UINT32 MinimumVoltageIn50mV : 10;
    UINT32 MaximumVoltageIn50mV : 10;
    UINT32 Battery : 2;
  } BatterySupplyPdoSink;
  struct {
    UINT32 OperationalCurrentIn10mA : 10;
    UINT32 MinimumVoltageIn50mV : 10;
    UINT32 MaximumVoltageIn50mV : 10;
    UINT32 VariableSupportNonBattery : 2;
  } VariableSupplyNonBatteryPdoSink;
} USBC_PD_POWER_DATA_OBJECT, *PUSBC_PD_POWER_DATA_OBJECT;