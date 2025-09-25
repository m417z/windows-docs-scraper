## Description

A buffer of metadata for the placeholder file or directory.

## Members

### `FileBasicInfo`

A structure that supplies basic information about the item: the size of the file in bytes (should be zero if the IsDirectory field is set to TRUE), the item’s timestamps, and its attributes.

### `EaInformation`

A structure that supplies extended attribute (EA) information about the item.

### `EaInformation.EaBufferSize`

The size in bytes of the extended attribute buffer. If there is no extended attribute information, this must be set to 0.

### `EaInformation.OffsetToFirstEa`

The offset, in bytes, from the start of the **PRJ_PLACEHOLDER_INFO** structure to the first FILE_FULL_EA_INFORMATION entry.

### `SecurityInformation`

Supplies custom security descriptor information about the item.

### `SecurityInformation.SecurityBufferSize`

The size, in bytes, of the custom security descriptor. If there is no custom security descriptor, this must be set to 0.

### `SecurityInformation.OffsetToSecurityDescriptor`

Specifies the offset, in bytes, from the start of the **PRJ_PLACEHOLDER_INFO** structure to the SECURITY_DESCRIPTOR structure.

### `StreamsInformation`

Supplies information about alternate data streams for the item.

### `StreamsInformation.StreamsInfoBufferSize`

The size, in bytes, of alternate data stream information for the placeholder. If there are no alternate data streams, this must be set to 0.

### `StreamsInformation.OffsetToFirstStreamInfo`

The offset, in bytes, from the start of the **PRJ_PLACEHOLDER_INFO** structure to the first FILE_STREAM_INFORMATION entry.

### `VariableData`

Start of the variable-length buffer to hold EAs, a custom security descriptor, and alternate data stream information.

### `versionInfo`

Version information for the placeholder (see [PrjMarkDirectoryAsPlaceholder](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjmarkdirectoryasplaceholder) for more information on PRJ_PLACEHOLDER_VERSION_INFO).