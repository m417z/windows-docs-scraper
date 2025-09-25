typedef struct _FILTER_VOLUME_STANDARD_INFORMATION {
  ULONG               NextEntryOffset;
  ULONG               Flags;
  ULONG               FrameID;
  FLT_FILESYSTEM_TYPE FileSystemType;
  USHORT              FilterVolumeNameLength;
  WCHAR               FilterVolumeName[1];
} FILTER_VOLUME_STANDARD_INFORMATION, *PFILTER_VOLUME_STANDARD_INFORMATION;