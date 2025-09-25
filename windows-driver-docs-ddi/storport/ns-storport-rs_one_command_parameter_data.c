typedef struct {
  UCHAR ReadWriteCommandDurationLimitsPage : 1;
  UCHAR Reserved : 7;
  UCHAR Support : 3;
  UCHAR CommandDurationLimitPage : 2;
  UCHAR MultipleLogicalUnits : 2;
  UCHAR CommandTimeoutsDescriptorPresent : 1;
  UCHAR CdbSize[2];
  UCHAR CdbUsageData[ANYSIZE_ARRAY];
} RS_ONE_COMMAND_PARAMETER_DATA, *PRS_ONE_COMMAND_PARAMETER_DATA;