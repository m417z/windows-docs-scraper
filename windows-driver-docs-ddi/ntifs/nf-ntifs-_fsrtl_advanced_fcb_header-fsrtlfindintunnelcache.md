# FsRtlFindInTunnelCache function

## Description

The **FsRtlFindInTunnelCache** routine searches for a matching entry in the tunnel cache that matches the specified name.

## Parameters

### `Cache` [in]

Pointer to a tunnel cache initialized by [**FsRtlInitializeTunnelCache**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializetunnelcache).

### `DirectoryKey`

Key value of the directory containing the file that is being created or renamed.

### `Name` [in]

Pointer to a Unicode string containing the new name for the file that is being renamed or created.

### `ShortName` [out]

Pointer to a caller-allocated Unicode string to receive the short name of the tunneled file. This string must be long enough to hold a full 8.3 file name. (Unlike **LongName**, **ShortName** is not grown dynamically.)

### `LongName` [out]

Pointer to a caller-allocated Unicode string to receive the long name of the tunneled file. If this string is not large enough to hold the tunneled name, **FsRtlFindInTunnelCache** replaces it with a larger system-allocated string. If such a string is allocated, the caller is responsible for detecting this case and freeing the new system-allocated string as well as the original caller-allocated string.

### `DataLength` [in, out]

On input, this is a pointer to a variable that specifies the length of the buffer pointed to by **Data**. On output, the same variable receives the length in bytes of the data written to the buffer.

### `Data` [out]

Pointer to a caller-allocated buffer to receive the data found in the tunnel cache.

## Return value

**FsRtlFindInTunnelCache** returns TRUE if a matching entry is found in the tunnel cache, FALSE otherwise.

## Remarks

File systems can call **FsRtlFindInTunnelCache** when a file name is added to a directory for a file that is being created or renamed. **FsRtlFindInTunnelCache** searches the tunnel cache for an entry that matches **DirKey** and **Name**. If one is found, **FsRtlFindInTunnelCache** fetches the cached information.

The match is performed as follows:

* The value of **DirKey** is compared against the entry's directory key. (This is the **DirectoryKey** value that was passed to **FsRtlAddToTunnelCache**.)

* If **KeyByShortName** was set to TRUE in the call to **FsRtlAddToTunnelCache**, the string pointed to by **Name** is compared against the short name of the tunneled file. Otherwise, it is compared against the long name.

The value of the buffer length variable pointed to by **DataLength** must be greater than or equal to the length in bytes of the data stored in the tunnel cache entry.

The caller is required to synchronize this call against [**FsRtlDeleteTunnelCache**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtldeletetunnelcache). In other words, a file system must ensure that it does not call **FsRtlFindInTunnelCache** and **FsRtlDeleteTunnelCache** at the same time from different threads.

## See also

[**FsRtlDeleteTunnelCache**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtldeletetunnelcache)

[**FsRtlInitializeTunnelCache**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializetunnelcache)

[**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)