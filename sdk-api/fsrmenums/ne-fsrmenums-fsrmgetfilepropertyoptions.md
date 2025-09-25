# FsrmGetFilePropertyOptions enumeration

## Description

Flags that defines how classification properties associated with a file are retrieved.

## Constants

### `FsrmGetFilePropertyOptions_None:0`

Retrieve the most up-to-date classification properties. Using this value may require more time than the
**FsrmGetFilePropertyOptions_NoRuleEvaluation** value.

### `FsrmGetFilePropertyOptions_NoRuleEvaluation:0x1`

Retrieve classification properties from cache or storage without using any rule evaluation.

### `FsrmGetFilePropertyOptions_Persistent:0x2`

After retrieving the classification properties (and possibly reclassifying the file in the process), store
the classification properties with the file.

**Windows Server 2008 R2:** This enumeration value is not supported before Windows Server 2012.

### `FsrmGetFilePropertyOptions_FailOnPersistErrors:0x4`

If the **FsrmGetFilePropertyOptions_Persistent** flag is set but the properties were
unable to be stored with the file, return a failure for the operation. If this flag is clear the operation will
not fail even though the properties were not persisted with the file.

**Windows Server 2008 R2:** This enumeration value is not supported before Windows Server 2012.

### `FsrmGetFilePropertyOptions_SkipOrphaned:0x8`

If the **FsrmGetFilePropertyOptions_Persistent** flag is set, skip any properties
stored with the file that are not also defined for the machine.

**Windows Server 2008 R2:** This enumeration value is not supported before Windows Server 2012.

## See also

[FSRM Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-enumerations)

[IFsrmClassificationManager::EnumFileProperties](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-enumfileproperties)

[IFsrmClassificationManager::GetFileProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-getfileproperty)