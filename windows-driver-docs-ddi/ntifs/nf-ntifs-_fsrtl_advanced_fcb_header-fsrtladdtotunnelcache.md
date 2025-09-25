# FsRtlAddToTunnelCache function

## Description

The **FsRtlAddToTunnelCache** routine caches a file name that is removed from a directory when a file is renamed or deleted.

## Parameters

### `Cache` [in]

Pointer to a tunnel cache initialized by [FsRtlInitializeTunnelCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializetunnelcache).

### `DirectoryKey` [in]

Key value of the directory containing the file that is being deleted or renamed. The directory key is a unique unsigned 64-bit identifier that is generated and assigned to the directory by the file system.

### `ShortName` [in]

Unicode string containing the short (8.3) name for the file. If *KeyByShortName* is **FALSE**, *ShortName* is optional.

### `LongName` [in]

Unicode string containing the long name for the file. A long file name is a name for a file or directory that exceeds the standard 8.3 file name format. If *KeyByShortName* is **TRUE**, *LongName* is optional.

### `KeyByShortName` [in]

Set to **TRUE** if the file name to be deleted from the directory is the short name for the file, **FALSE** if it is the long name.

### `DataLength` [in]

Length in bytes of the information to be stored in the tunnel cache entry for this file. The value of this parameter is file-system-specific, but it must be the same for all entries in the tunnel cache.

### `Data` [in]

Pointer to a buffer that contains file-system-specific information to be stored in the tunnel cache entry for this file.

## Remarks

When a file name is removed from a directory (for a file that is being renamed or deleted), the file system can cache the file name by calling **FsRtlAddToTunnelCache**. The purpose of the tunnel cache is to propagate file properties if a new file is created that has the same long or short name as the file just deleted or renamed.

**FsRtlAddToTunnelCache** creates a new entry that contains the specified file name and directory key, and adds the entry to the tunnel cache for the mounted volume where the file is being removed or deleted. This entry can also contain a fixed-size data packet of file-system-specific information for the file.

The caller is required to synchronize this call against [FsRtlDeleteTunnelCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtldeletetunnelcache). In other words, a file system must ensure that it does not call **FsRtlAddToTunnelCache** and **FsRtlDeleteTunnelCache** at the same time from different threads.

For more information about file name tunneling, see [Microsoft Knowledge Base Article 172190](https://go.microsoft.com/fwlink/p/?linkid=3100&id=172190).

## See also

[FsRtlDeleteKeyFromTunnelCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtldeletekeyfromtunnelcache)

[FsRtlDeleteTunnelCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtldeletetunnelcache)

[FsRtlInitializeTunnelCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializetunnelcache)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)