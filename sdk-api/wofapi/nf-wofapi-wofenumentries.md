# WofEnumEntries function

## Description

Enumerates all the data sources from a specified provider for a specified volume.

## Parameters

### `VolumeName` [in]

The volume name hosting the files for which the backing data sources are requested.

### `Provider` [in]

Indicates which provider’s data sources are being requested. Supported providers for this operation are:

|  |  |
| --- | --- |
| WOF_PROVIDER_WIM | Indicates that the function should return the WIM files which are providing data for placeholder files on the specified volume. |

### `EnumProc` [in]

The callback function for each data source. The enumeration will stop if *EnumProc* returns **FALSE**.

### `UserData` [in, optional]

User defined data passed to *EnumProc*.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[FSCTL_ENUM_OVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-enum-overlay)