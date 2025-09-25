typedef enum _FSINFOCLASS {
  FileFsVolumeInformation,
  FileFsLabelInformation,
  FileFsSizeInformation,
  FileFsDeviceInformation,
  FileFsAttributeInformation,
  FileFsControlInformation,
  FileFsFullSizeInformation,
  FileFsObjectIdInformation,
  FileFsDriverPathInformation,
  FileFsVolumeFlagsInformation,
  FileFsSectorSizeInformation,
  FileFsDataCopyInformation,
  FileFsMetadataSizeInformation,
  FileFsFullSizeInformationEx,
  FileFsGuidInformation,
  FileFsMaximumInformation
} FS_INFORMATION_CLASS, *PFS_INFORMATION_CLASS;