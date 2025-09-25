typedef enum _FsrmPropertyBagFlags {
  FsrmPropertyBagFlags_UpdatedByClassifier = 0x1,
  FsrmPropertyBagFlags_FailedLoadingProperties = 0x2,
  FsrmPropertyBagFlags_FailedSavingProperties = 0x4,
  FsrmPropertyBagFlags_FailedClassifyingProperties = 0x8
} FsrmPropertyBagFlags;