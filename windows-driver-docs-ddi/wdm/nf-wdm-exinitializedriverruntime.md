## Description

POOL_NX_OPTIN allows device drivers to dynamically opt-in to making
non-paged pool allocations non-executable by default based on whether or not
this is supported by the version of the operating system. Device drivers
must call ExInitializeDriverRuntime (DrvRtPoolNxOptIn) during driver
initialization to dynamically opt-in. This opt-in method should be used by
drivers that are designed to run on versions of Windows that may or may not
support NX non-paged pool allocations.

## Parameters

### `RuntimeFlags`

## Remarks

## See also

[Single Binary Opt-In: POOL_NX_OPTIN](https://learn.microsoft.com/windows-hardware/drivers/kernel/single-binary-opt-in-pool-nx-optin)