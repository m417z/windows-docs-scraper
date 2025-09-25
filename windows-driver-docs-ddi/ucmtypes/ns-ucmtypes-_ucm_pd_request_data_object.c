typedef union _UCM_PD_REQUEST_DATA_OBJECT {
  ULONG  Ul;
  struct {
    unsigned Reserved1 : 28;
    unsigned ObjectPosition : 3;
    unsigned Reserved2 : 1;
  } Common;
  struct {
    unsigned MaximumOperatingCurrentIn10mA : 10;
    unsigned OperatingCurrentIn10mA : 10;
    unsigned Reserved1 : 4;
    unsigned NoUsbSuspend : 1;
    unsigned UsbCommunicationCapable : 1;
    unsigned CapabilityMismatch : 1;
    unsigned GiveBackFlag : 1;
    unsigned ObjectPosition : 3;
    unsigned Reserved2 : 1;
  } FixedAndVariableRdo;
  struct {
    unsigned MaximumOperatingPowerIn250mW : 10;
    unsigned OperatingPowerIn250mW : 10;
    unsigned Reserved1 : 4;
    unsigned NoUsbSuspend : 1;
    unsigned UsbCommunicationCapable : 1;
    unsigned CapabilityMismatch : 1;
    unsigned GiveBackFlag : 1;
    unsigned ObjectPosition : 3;
    unsigned Reserved2 : 1;
  } BatteryRdo;
} UCM_PD_REQUEST_DATA_OBJECT, *PUCM_PD_REQUEST_DATA_OBJECT;