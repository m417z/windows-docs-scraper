# DSTORAGE_CONFIGURATION1 structure (dstorage.h)

DirectStorage configuration; adds an option to enable file buffering. Zero-initializing this will result in the default values.

## Members

`NumSubmitThreads`

Sets the number of threads to use for submitting IO operations. Specifying 0 means use the system's best guess at a good value. Default == 0.

`NumBuiltInCpuDecompressionThreads`

Sets the number of threads to be used by the DirectStorage runtime to decompress data using the CPU for built-in compressed formats that can't be decompressed using the GPU. Specifying 0 means to use the system's best guess at a good value. Specifying **DSTORAGE_DISABLE_BUILTIN_CPU_DECOMPRESSION** means that no decompression threads will be created, and the title is fully responsible for checking the custom decompression queue and pulling off *all* entries to decompress. Default == 0.

`ForceMappingLayer`

Forces the use of the IO mapping layer, even when running on an operating system that doesn't require it. This might be useful during development, but should be set to `FALSE` for release. Default == `FALSE`.

`DisableBypassIO`

Disables the use of the bypass IO optimization, even if it is available. This might be useful during development, but should be set to `FALSE` for release; unless you set *ForceFileBuffering* to `TRUE`. Default == `FALSE`.

`DisableTelemetry`

Disables the reporting of telemetry data when set to `TRUE`. Telemetry data is enabled by default in the DirectStorage runtime. Default == `FALSE`.

`DisableGpuDecompressionMetacommand`

Disables the use of a decompression metacommand, even if one is available. This will force the runtime to use the built-in GPU decompression fallback shader. This may be useful during development, but should be set to `FALSE` for release. Default == FALSE.

`DisableGpuDecompression`

Disables the use of GPU based decompression, even if it is available. This will force the runtime to use the CPU. Default == `FALSE`.

`ForceFileBuffering`

Forces the use of the built-in file caching behaviors supported within the Windows operating system by not setting **FILE_FLAG_NO_BUFFERING** when opening files (see [File buffering](https://learn.microsoft.com/windows/win32/fileio/file-buffering)). Default == `FALSE`.

You must set *DisableBypassIO* to `TRUE` when using this option, otherwise **E_DSTORAGE_FILEBUFFERING_REQUIRES_DISABLED_BYPASSIO** will be returned. It's the title's responsibility to know when to use this setting. This feature should be enabled only for slower HDD drives that will benefit from the OS file buffering features.

> [!WARNING]
> Enabling file buffering on high speed drives might reduce overall performance when reading from that drive because BypassIO is also disabled.

## Requirements

|   |   |
| ---- |:---- |
| **Header** | dstorage.h |