ISDSC_STATUS ISDSC_API GetIScsiTargetInformationA(
  [in]           PSTR                     TargetName,
  [in, optional] PSTR                     DiscoveryMechanism,
  [in]           TARGET_INFORMATION_CLASS InfoClass,
  [in, out]      PULONG                   BufferSize,
  [out]          PVOID                    Buffer
);