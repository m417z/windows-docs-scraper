# WofWimSuspendEntry function

## Description

Temporarily removes a WIM data source from backing files on a volume until the volume is remounted or the data source is updated with [WofWimUpdateEntry](https://learn.microsoft.com/windows/desktop/api/wofapi/nf-wofapi-wofwimupdateentry).

## Parameters

### `VolumeName` [in]

The volume name which contained files whose data was provided by the WIM.

### `DataSourceId` [in]

Identifies the WIM entry.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the volume currently has files whose data is derived from the WIM file, the data for those files will become temporarily inaccessible. This should not be performed on a WIM from which the system is currently operating.

## See also

[FSCTL_SUSPEND_OVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-suspend-overlay)