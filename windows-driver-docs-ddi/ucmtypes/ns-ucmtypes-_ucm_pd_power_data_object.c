typedef union _UCM_PD_POWER_DATA_OBJECT {
  ULONG  Ul;
  struct {
    unsigned Reserved : 30;
    unsigned Type : 2;
  } Common;
  struct {
    unsigned MaximumCurrentIn10mA : 10;
    unsigned VoltageIn50mV : 10;
    unsigned PeakCurrent : 2;
    unsigned Reserved : 3;
    unsigned DataRoleSwap : 1;
    unsigned UsbCommunicationCapable : 1;
    unsigned ExternallyPowered : 1;
    unsigned UsbSuspendSupported : 1;
    unsigned DualRolePower : 1;
    unsigned FixedSupply : 2;
  } FixedSupplyPdo;
  struct {
    unsigned MaximumCurrentIn10mA : 10;
    unsigned MinimumVoltageIn50mV : 10;
    unsigned MaximumVoltageIn50mV : 10;
    unsigned VariableSupportNonBattery : 2;
  } VariableSupplyNonBatteryPdo;
  struct {
    unsigned MaximumAllowablePowerIn250mW : 10;
    unsigned MinimumVoltageIn50mV : 10;
    unsigned MaximumVoltageIn50mV : 10;
    unsigned Battery : 2;
  } BatterySupplyPdo;
} UCM_PD_POWER_DATA_OBJECT, *PUCM_PD_POWER_DATA_OBJECT;