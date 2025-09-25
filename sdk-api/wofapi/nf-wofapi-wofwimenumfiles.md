# WofWimEnumFiles function

## Description

Enumerates all of the files which are being backed by a specified WIM data source on a specified volume.

## Parameters

### `VolumeName` [in]

The path to the volume which hosts WIM-backed files.

### `DataSourceId` [in]

Identifier used to identify the WIM entry.

### `EnumProc` [in]

The callback function for file provided by the WIM entry.

### `UserData` [in, optional]

Optional user defined data passed to *EnumProc*.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.