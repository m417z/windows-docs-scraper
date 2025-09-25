## Description

> [!WARNING]
> UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **READ_REGISTER_ULONG64** function reads a ULONG64 value from the specified register address.

## Parameters

### `Register` [in]

A pointer to the register address, which must be a mapped range in memory space.

## Return value

**READ_REGISTER_ULONG64** returns the ULONG64 value that is read from the specified port address.

## Remarks

For more information, see [Reading and Writing to Device Registers in UMDF 1.x Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/reading-and-writing-to-device-registers-in-umdf-1-x-drivers).