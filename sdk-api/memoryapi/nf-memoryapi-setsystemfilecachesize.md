# SetSystemFileCacheSize function

## Description

Limits the size of the working set for the file system cache.

## Parameters

### `MinimumFileCacheSize` [in]

The minimum size of the file cache, in bytes. The virtual memory manager attempts to keep at least this much memory resident in the system file cache.

To flush the cache, specify `(SIZE_T) -1`.

### `MaximumFileCacheSize` [in]

The maximum size of the file cache, in bytes. The virtual memory manager enforces this limit only if this call or a previous call to **SetSystemFileCacheSize** specifies **FILE_CACHE_MAX_HARD_ENABLE**.

To flush the cache, specify `(SIZE_T) -1`.

### `Flags` [in]

The flags that enable or disable the file cache limits. If this parameter is 0 (zero), the size limits retain the current setting, which is either disabled or enabled.

| Value | Meaning |
| --- | --- |
| **FILE_CACHE_MAX_HARD_DISABLE**<br><br>0x2 | Disable the maximum size limit.<br><br>The **FILE_CACHE_MAX_HARD_DISABLE** and **FILE_CACHE_MAX_HARD_ENABLE** flags are mutually exclusive. |
| **FILE_CACHE_MAX_HARD_ENABLE**<br><br>0x1 | Enable the maximum size limit.<br><br>The **FILE_CACHE_MAX_HARD_DISABLE** and **FILE_CACHE_MAX_HARD_ENABLE** flags are mutually exclusive. |
| **FILE_CACHE_MIN_HARD_DISABLE**<br><br>0x8 | Disable the minimum size limit.<br><br>The **FILE_CACHE_MIN_HARD_DISABLE** and **FILE_CACHE_MIN_HARD_ENABLE** flags are mutually exclusive. |
| **FILE_CACHE_MIN_HARD_ENABLE**<br><br>0x4 | Enable the minimum size limit.<br><br>The **FILE_CACHE_MIN_HARD_DISABLE** and **FILE_CACHE_MIN_HARD_ENABLE** flags are mutually exclusive. |

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is 0 (zero). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The calling process must enable the **SE_INCREASE_QUOTA_NAME** privilege.

Setting the *MaximumFileCacheSize* parameter to a very low value can adversely affect system performance.

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0502 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

The **FILE_CACHE_*** constants will be defined in the Windows header files starting with the Windows SDK for Windows Server 2008. If you are using header files from an earlier version of the SDK, add the following definitions to your code.

```cpp
#ifndef FILE_CACHE_FLAGS_DEFINED

#define FILE_CACHE_MAX_HARD_ENABLE      0x00000001
#define FILE_CACHE_MAX_HARD_DISABLE     0x00000002
#define FILE_CACHE_MIN_HARD_ENABLE      0x00000004
#define FILE_CACHE_MIN_HARD_DISABLE     0x00000008

#endif // FILE_CACHE_FLAGS_DEFINED

```

## See also

[GetSystemFileCacheSize](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-getsystemfilecachesize)

[Memory Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)