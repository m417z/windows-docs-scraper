typedef struct {
  UCHAR OperationCode;
  UCHAR Reserved;
  UCHAR ServiceAction[2];
  UCHAR Reserved1;
  UCHAR ServiceActionValid : 1;
  UCHAR CommandTimeoutsDescriptorPresent : 1;
  UCHAR CommandDurationLimitPage : 2;
  UCHAR MultipleLogicalUnits : 2;
  UCHAR ReadWriteCommandDurationLimitsPage : 1;
  UCHAR Reserved2 : 1;
  UCHAR CdbLength[2];
} RS_COMMAND_DESCRIPTOR, *PRS_COMMAND_DESCRIPTOR;