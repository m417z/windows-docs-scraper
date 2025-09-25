BOOL GetAppContainerNamedObjectPath(
  [in, optional]  HANDLE Token,
  [in, optional]  PSID   AppContainerSid,
  [in]            ULONG  ObjectPathLength,
  [out, optional] LPWSTR ObjectPath,
  [out]           PULONG ReturnLength
);