# IVssSnapshotMgmt2::GetMinDiffAreaSize

## Description

Returns the current minimum size of the shadow copy storage area.

## Parameters

### `pllMinDiffAreaSize` [out]

A pointer to a variable that receives the minimum size, in bytes, of the shadow copy storage area.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The shadow copy storage area minimum size is a per-computer setting that is specified by the **MinDiffAreaFileSize** registry key. For more information, see the entry for **MinDiffAreaFileSize** in [Registry Keys and Values for Backup and Restore](https://learn.microsoft.com/windows/desktop/Backup/registry-keys-for-backup-and-restore).

## See also

[IVssSnapshotMgmt2](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nn-vsmgmt-ivsssnapshotmgmt2)