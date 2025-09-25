typedef enum _MSV1_0_LOGON_SUBMIT_TYPE {
  MsV1_0InteractiveLogon = 2,
  MsV1_0Lm20Logon,
  MsV1_0NetworkLogon,
  MsV1_0SubAuthLogon,
  MsV1_0WorkstationUnlockLogon = 7,
  MsV1_0S4ULogon = 12,
  MsV1_0VirtualLogon = 82,
  MsV1_0NoElevationLogon = 83,
  MsV1_0LuidLogon = 84
} MSV1_0_LOGON_SUBMIT_TYPE, *PMSV1_0_LOGON_SUBMIT_TYPE;