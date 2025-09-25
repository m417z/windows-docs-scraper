# FsrmFileSystemPropertyId enumeration

## Description

Defines the possible types of file system property ids.

## Constants

### `FsrmFileSystemPropertyId_Undefined:0`

The file system property id is not used. This is the default.

### `FsrmFileSystemPropertyId_FileName:1`

The file system property id is the filename, including the extension.

### `FsrmFileSystemPropertyId_DateCreated:2`

The file system property id is the file's creation time.

### `FsrmFileSystemPropertyId_DateLastAccessed:3`

The file system property id is the file's last accessed time.

### `FsrmFileSystemPropertyId_DateLastModified:4`

The file system property id is the file's last modified time.

### `FsrmFileSystemPropertyId_DateNow:5`

The file system property id is the current time.

## See also

[FSRM Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-enumerations)

[IFsrmFileConditionProperty.PropertyId](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfileconditionproperty-get_propertyid)