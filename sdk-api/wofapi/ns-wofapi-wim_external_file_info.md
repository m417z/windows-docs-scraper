## Description

Defines metadata specific to files provided by WOF_PROVIDER_WIM.

## Members

### `DataSourceId`

Specifies the data source from which the file’s data is being provided.

### `Flags`

Specifies one or more flags for this data file. When creating a new backed file, this member should be zero. When querying the state of an existing file, this member can include WIM_ENTRY_FLAG_NOT_ACTIVE, indicating the data source is removed or the WIM file is not found, or WIM_ENTRY_FLAG_SUSPENDED indicating that the data source is not currently in use but could become in use on demand.

### `ResourceHash`

Specifies the identifier of the file within the WIM file.