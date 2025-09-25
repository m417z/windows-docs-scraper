# FsrmFileManagementType enumeration

## Description

Defines the file management job types.

## Constants

### `FsrmFileManagementType_Unknown:0`

The file management type is unknown; do not use this value.

### `FsrmFileManagementType_Expiration:1`

The file management job expires files meeting the specified criteria.

### `FsrmFileManagementType_Custom:2`

This file management job runs a custom action on files meeting the specified criteria.

### `FsrmFileManagementType_Rms:3`

The file management jobs runs an RMS action on files meeting the specified criteria.

**Windows Server 2008 R2:** This enumeration value is not supported before Windows Server 2012.

## See also

[FSRM Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-enumerations)

[IFsrmFileManagementJob.OperationType](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjob-get_operationtype)