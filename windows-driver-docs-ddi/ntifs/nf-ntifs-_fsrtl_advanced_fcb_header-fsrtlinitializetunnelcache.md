# FsRtlInitializeTunnelCache function

## Description

The **FsRtlInitializeTunnelCache** routine initializes a new tunnel cache for a volume.

## Parameters

### `Cache` [in]

Pointer to a per-volume TUNNEL structure for which the caller must provide resident storage in nonpaged pool.

## Remarks

**FsRtlInitializeTunnelCache** initializes a new tunnel cache. File systems must call **FsRtlInitializeTunnelCache** before using any other **FsRtl...TunnelCache** routines on the tunnel cache.

File systems can use a per-volume tunnel cache to cache file names and other metadata for files that are being renamed or deleted.

Entries are added to the tunnel cache by calling [FsRtlAddToTunnelCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtladdtotunnelcache). Each entry contains the file name and directory key for a file, and can also contain a fixed-size data packet of file-system-specific information. When the tunnel cache becomes full, older entries are removed automatically.

For more information about file name tunneling, see [Microsoft Knowledge Base Article 172190](https://go.microsoft.com/fwlink/p/?linkid=3100&id=172190).

## See also

[FsRtlAddToTunnelCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtladdtotunnelcache)