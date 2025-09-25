# FsRtlDeleteTunnelCache function

## Description

The **FsRtlDeleteTunnelCache** routine deletes a tunnel cache.

## Parameters

### `Cache` [in]

Pointer to the tunnel cache structure to delete. The tunnel cache must have been initialized by calling [FsRtlInitializeTunnelCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializetunnelcache).

## Remarks

**FsRtlDeleteTunnelCache** deletes all information contained in the tunnel cache. After the call to **FsRtlDeleteTunnelCache**, the tunnel cache is no longer valid.

Callers are responsible for synchronizing access to the **FsRtlDeleteTunnelCache** call. In other words, a file system must ensure that it does not call **FsRtlDeleteTunnelCache** at the same time it is calling another tunnel cache routine from a different thread.

For more information about file name tunneling, see [Microsoft Knowledge Base Article 172190](https://go.microsoft.com/fwlink/p/?linkid=3100&id=172190).

## See also

[FsRtlInitializeTunnelCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializetunnelcache)