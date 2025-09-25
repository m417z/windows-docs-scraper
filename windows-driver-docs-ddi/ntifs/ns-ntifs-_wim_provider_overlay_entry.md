# WIM_PROVIDER_OVERLAY_ENTRY structure

## Description

The **WIM_PROVIDER_OVERLAY_ENTRY** structure contains the Windows Image Format (WIM) file configuration information for a data source entry. It is used to identify specific WIM file names and indices that supply data to externally backed files on a volume.

## Members

### `NextEntryOffset`

The offset to the next **WIM_PROVIDER_OVERLAY_ENTRY** structure returned in the enumeration. Set to 0 if there are no further entries.

### `DataSourceId`

The specific identifier an overlay entry. A single WIM GUID, such as in the **WimGuid** member, may have multiple data source identifiers.

### `WimGuid`

A unique identifier of a WIM file.

### `WimFileNameOffset`

The offset, in bytes, from the beginning of this structure of the file name for the WIM file to add as a backing source. The file name is a NULL terminated string of **WCHAR** character values.

### `WimType`

The type of WIM file set as a backing source. The WIM file type is set to one of the following values.

| Value | Meaning |
| ----- | ------- |
| WIM_BOOT_OS_WIM | The WIM file contains Windows system files. |
| WIM_BOOT_NOT_OS_WIM | The WIM file contains non-operating system files. |

### `WimIndex`

The index of the image in the WIM file specified at **WimFileNameOffset**.

### `Flags`

The status flags for the WIM provider. Set to 0 when active. Otherwise **Flags** is set to one of the following values.

| Value | Meaning |
| ----- | ------- |
| WIM_PROVIDER_EXTERNAL_FLAG_NOT_ACTIVE | The WIM provider is not active, which can occur when the WIM file is not found. In this case, the WIM file will not be recovered. |
| WIM_PROVIDER_EXTERNAL_FLAG_SUSPENDED | The provider is dismounted. Recovery will be attempted. |

## See also

[**FSCTL_ENUM_OVERLAY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-enum-overlay)