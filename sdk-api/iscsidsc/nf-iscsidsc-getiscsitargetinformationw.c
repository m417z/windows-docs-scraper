ISDSC_STATUS ISDSC_API GetIScsiTargetInformationW(
  [in]           PWSTR                    TargetName,
  [in, optional] PWSTR                    DiscoveryMechanism,
  [in]           TARGET_INFORMATION_CLASS InfoClass,
  [in, out]      PULONG                   BufferSize,
  [out]          PVOID                    Buffer
);