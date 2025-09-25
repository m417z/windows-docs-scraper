typedef struct tagRPC_EXTENDED_ERROR_INFO {
  ULONG             Version;
  LPWSTR            ComputerName;
  ULONG             ProcessID;
  union {
    SYSTEMTIME    SystemTime;
    FILETIME      FileTime;
    LARGE_INTEGER KernelTime;
  } u;
  ULONG             GeneratingComponent;
  ULONG             Status;
  USHORT            DetectionLocation;
  USHORT            Flags;
  int               NumberOfParameters;
  RPC_EE_INFO_PARAM Parameters[MaxNumberOfEEInfoParams];
} RPC_EXTENDED_ERROR_INFO;