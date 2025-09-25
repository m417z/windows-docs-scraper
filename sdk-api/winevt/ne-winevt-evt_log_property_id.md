# EVT_LOG_PROPERTY_ID enumeration

## Description

Defines the identifiers that identify the log file metadata properties of a channel or log file.

## Constants

### `EvtLogCreationTime:0`

Identifies the property that contains the time that the channel or log file was created. The variant type for this property is **EvtVarTypeFileTime**.

### `EvtLogLastAccessTime`

Identifies the property that contains the last time that the channel or log file was accessed. The variant type for this property is **EvtVarTypeFileTime**.

### `EvtLogLastWriteTime`

Identifies the property that contains the last time that the channel or log file was written to. The variant type for this property is **EvtVarTypeFileTime**.

### `EvtLogFileSize`

Identifies the property that contains the size of the file, in bytes. The variant type for this property is **EvtVarTypeUInt64**.

### `EvtLogAttributes`

Identifies the property that contains the file attributes (for details on the file attributes, see the [GetFileAttributesEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileattributesexa) function). The variant type for this property is **EvtVarTypeUInt32**.

### `EvtLogNumberOfLogRecords`

Identifies the property that contains the number of records in the channel or log file. The variant type for this property is **EvtVarTypeUInt64**.

### `EvtLogOldestRecordNumber`

Identifies the property that contains the record number of the oldest event in the channel or log file. The variant type for this property is **EvtVarTypeUInt64**.

### `EvtLogFull`

Identifies the property that you use to determine whether the channel or log file is full. The variant type for this property is **EvtVarTypeBoolean**. The channel is full if another event cannot be written to the channel (for example, if the channel is sequential and maximum size is reached). The property will always be false if the channel is circular or the sequential log is automatically backed up.

## See also

[EvtGetLogInfo](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtgetloginfo)