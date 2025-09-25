# FsrmPropertyFlags enumeration

## Description

Defines flag values that provide additional information about a classification property.

## Constants

### `FsrmPropertyFlags_None:0`

### `FsrmPropertyFlags_Orphaned:0x1`

The property does not have a corresponding property definition defined in FSRM.

### `FsrmPropertyFlags_RetrievedFromCache:0x2`

The value of the property was retrieved from the cache during this classification session.

### `FsrmPropertyFlags_RetrievedFromStorage:0x4`

The value of the property was retrieved from the file or database during this classification session.

### `FsrmPropertyFlags_SetByClassifier:0x8`

The value of the property was set by a classification rule during the last classification run.

### `FsrmPropertyFlags_Deleted:0x10`

The property was deleted by
[IFsrmClassificationManager::ClearFileProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-clearfileproperty).

### `FsrmPropertyFlags_Reclassified:0x20`

The property value from storage was changed to a different value by a classifier.

### `FsrmPropertyFlags_AggregationFailed:0x40`

There are values from multiple sources that could not be aggregated together.

### `FsrmPropertyFlags_Existing:0x80`

The property already exists in storage.

### `FsrmPropertyFlags_FailedLoadingProperties:0x100`

The property may only be partially classified because a failure occurred while loading properties from
storage.

### `FsrmPropertyFlags_FailedClassifyingProperties:0x200`

The property may only be partially classified because a failure occurred while classifying
properties.

### `FsrmPropertyFlags_FailedSavingProperties:0x400`

The property failed to be saved by the storage module with the highest precedence.

**Windows Server 2008 R2:** This enumeration value is not supported before Windows Server 2012.

### `FsrmPropertyFlags_Secure:0x800`

The property is defined to be used for security purposes or came from secure storage.

**Windows Server 2008 R2:** This enumeration value is not supported before Windows Server 2012.

### `FsrmPropertyFlags_PolicyDerived:0x1000`

The property value originally came from a classification policy.

**Windows Server 2008 R2:** This enumeration value is not supported before Windows Server 2012.

### `FsrmPropertyFlags_Inherited:0x2000`

The property value was inherited from the property value of the file's parent folder.

**Windows Server 2008 R2:** This enumeration value is not supported before Windows Server 2012.

### `FsrmPropertyFlags_Manual:0x4000`

The property value was set manually.

**Windows Server 2008 R2:** This enumeration value is not supported before Windows Server 2012.

### `FsrmPropertyFlags_ExplicitValueDeleted:0x8000`

An explicit property value was deleted and replaced with an inherited value.

**Windows Server 2008 R2:** This enumeration value is not supported before Windows Server 2012.

### `FsrmPropertyFlags_PropertyDeletedFromClear:0x10000`

The property has been deleted due to a rule marked with clear property.

**Windows Server 2012 and Windows Server 2008 R2:** This enumeration value is not supported before Windows Server 2012 R2.

### `FsrmPropertyFlags_PropertySourceMask`

This mask shows which flags are used to indicate the source of the property and is equivalent to the
following flag combination:

`(FsrmPropertyFlags_RetrievedFromCache | FsrmPropertyFlags_RetrievedFromStorage | FsrmPropertyFlags_SetByClassifier)`

### `FsrmPropertyFlags_PersistentMask`

This mask shows which flags are persisted by the cache and secure storage modules and is equivalent to the
following flag combination:

`(FsrmPropertyFlags_PolicyDerived | FsrmPropertyFlags_Manual)`

**Windows Server 2008 R2:** This enumeration value is not supported before Windows Server 2012.

## Remarks

The **FsrmPropertyFlags_SetByClassifier** flag is set in the following cases:

* This is the first time the property value is being applied.
* The execution option of the classification rule applying the value is set to
  **FsrmExecutionOption_ReEvaluate_IgnoreExistingValue**.
* The execution option of the classification rule applying the value is set to
  **FsrmExecutionOption_ReEvaluate_ConsiderExistingValue** and the aggregation policy set
  the value specified by the rule.

## See also

[IFsrmProperty.PropertyFlags](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmproperty-get_propertyflags)