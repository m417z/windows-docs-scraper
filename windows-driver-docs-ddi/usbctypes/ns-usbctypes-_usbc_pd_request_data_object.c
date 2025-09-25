typedef union _USBC_PD_REQUEST_DATA_OBJECT {
  UINT32 U;
  struct {
    UINT32 Reserved1 : 28;
    UINT32 ObjectPosition : 3;
    UINT32 Reserved2 : 1;
  } Common;
  struct {
    UINT32 MaximumOperatingCurrentIn10mA : 10;
    UINT32 OperatingCurrentIn10mA : 10;
    UINT32 Reserved1 : 6;
    UINT32 CapabilityMismatch : 1;
    UINT32 GiveBackFlag : 1;
    UINT32 ObjectPosition : 3;
    UINT32 Reserved2 : 1;
  } FixedAndVariableRdo;
  struct {
    UINT32 MaximumOperatingPowerIn250mW : 10;
    UINT32 OperatingPowerIn250mW : 10;
    UINT32 Reserved1 : 6;
    UINT32 CapabilityMismatch : 1;
    UINT32 GiveBackFlag : 1;
    UINT32 ObjectPosition : 3;
    UINT32 Reserved2 : 1;
  } BatteryRdo;
  struct {
    UINT32 OperatingCurrentIn50mA : 7;
    UINT32 Reserved1 : 2;
    UINT32 OutputVoltageIn20mV : 11;
    UINT32 Reserved2 : 3;
    UINT32 UnchunkedExtendedMessagesSupported : 1;
    UINT32 Reserved3 : 2;
    UINT32 CapabilityMismatch : 1;
    UINT32 Reserved4 : 1;
    UINT32 ObjectPosition : 3;
    UINT32 Reserved5 : 1;
  } ProgrammableRdo;
} USBC_PD_REQUEST_DATA_OBJECT, *PUSBC_PD_REQUEST_DATA_OBJECT;