# FsRtlDeleteKeyFromTunnelCache function

## Description

The **FsRtlDeleteKeyFromTunnelCache** routine deletes any tunnel cache entries for files in a directory that is being deleted.

## Parameters

### `Cache` [in]

A pointer to a tunnel cache that was initialized by [FsRtlInitializeTunnelCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializetunnelcache).

### `DirectoryKey`

The directory key value for the directory that is being removed. For more information, see the reference entry for [**FsRtlInitializeTunnelCache**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializetunnelcache).

## Remarks

File systems call **FsRtlDeleteKeyFromTunnelCache** when deleting a directory from a volume. **FsRtlDeleteKeyFromTunnelCache** deletes all tunnel cache entries whose directory keys match the value specified in the *DirKey* parameter.

To delete the tunnel cache, use [FsRtlDeleteTunnelCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtldeletetunnelcache).

The caller is required to synchronize this call against [FsRtlDeleteTunnelCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtldeletetunnelcache). In other words, a file system must ensure that it does not call **FsRtlDeleteKeyFromTunnelCache** and **FsRtlDeleteTunnelCache** at the same time from different threads.

For more information about file name tunneling, see [Microsoft Knowledge Base Article 172190](https://go.microsoft.com/fwlink/p/?linkid=3100&id=172190).

## See also

[FsRtlDeleteTunnelCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtldeletetunnelcache)

[FsRtlInitializeTunnelCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializetunnelcache)