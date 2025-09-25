typedef struct {
  ULONG       BufferSize;
  ULONG       NextWmiRegInfo;
  ULONG       RegistryPath;
  ULONG       MofResourceName;
  ULONG       GuidCount;
  WMIREGGUIDW WmiRegGuid[];
} WMIREGINFOW, *PWMIREGINFOW;