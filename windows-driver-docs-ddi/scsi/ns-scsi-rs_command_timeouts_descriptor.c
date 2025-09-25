typedef struct {
  UCHAR DescriptorLength[2];
  UCHAR Reserved;
  UCHAR CommandSpecific;
  UCHAR NominalCommandProcessingTimeoutInSec[4];
  UCHAR RecommendedCommandTimeoutInSec[4];
} RS_COMMAND_TIMEOUTS_DESCRIPTOR, *PRS_COMMAND_TIMEOUTS_DESCRIPTOR;