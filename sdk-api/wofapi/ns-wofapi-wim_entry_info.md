# WIM_ENTRY_INFO structure

## Description

Defines metadata specific to each WIM data source hosted on a volume.

## Members

### `WimEntryInfoSize`

Specifies the size of the structure. Should be initialized to sizeof(WIM_ENTRY_INFO).

### `WimType`

Specifies the type of the WIM. Valid values are WIM_BOOT_OS_WIM and zero, which implies the WIM is not an operating system WIM.

### `DataSourceId`

Specifies a unique identifier for this data source.

### `WimGuid`

Specifies the GUID which is stored in the WIM file’s header.

### `WimPath`

Specifies a full path to the WIM file.

### `WimIndex`

Specifies the index within the WIM which is described by this data source.

### `Flags`

Specifies one or more flags for this data source. Can include WIM_ENTRY_FLAG_NOT_ACTIVE, indicating a data source which is removed or where the WIM file is not found, or WIM_ENTRY_FLAG_SUSPENDED indicating that the data source is not currently in use but could become in use on demand. If neither flag is present, the WIM is in active use.