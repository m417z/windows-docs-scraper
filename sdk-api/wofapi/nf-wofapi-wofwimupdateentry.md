# WofWimUpdateEntry function

## Description

Updates a WIM entry to point to a different WIM file location.

## Parameters

### `VolumeName` [in]

The volume name which contains files whose data is provided by the WIM.

### `DataSourceId` [in]

Identifies the WIM entry.

### `NewWimPath` [in]

The new location of the WIM file.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.