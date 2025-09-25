# FsrmPropertyBagFlags enumeration

## Description

Defines flag values that provide additional information about the property bag.

## Constants

### `FsrmPropertyBagFlags_UpdatedByClassifier:0x1`

The properties in the property bag were updated by a classifier.

### `FsrmPropertyBagFlags_FailedLoadingProperties:0x2`

The properties in the property bag may only be partially classified because a failure occurred while loading properties from storage.

### `FsrmPropertyBagFlags_FailedSavingProperties:0x4`

The properties in the property bag failed to be saved by the storage module with the highest precedence.

### `FsrmPropertyBagFlags_FailedClassifyingProperties:0x8`

The properties in the property bag may only be partially classified because a failure occurred while classifying properties.

## See also

[IFsrmPropertyBag::PropertyBagFlags](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmpropertybag-get_propertybagflags)