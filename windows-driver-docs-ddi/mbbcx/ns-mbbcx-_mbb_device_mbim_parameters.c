typedef struct _MBB_DEVICE_MBIM_PARAMETERS {
  ULONG                     Size;
  MBB_MBIM_VERSION          Version;
  MBB_MBIM_EXTENDED_VERSION ExtendedVersion;
  ULONG                     MaximumFragmentSize;
} MBB_DEVICE_MBIM_PARAMETERS, *PMBB_DEVICE_MBIM_PARAMETERS;