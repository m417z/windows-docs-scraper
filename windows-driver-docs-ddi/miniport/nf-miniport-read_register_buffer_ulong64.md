## Description

> [!WARNING]
> UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **READ_REGISTER_BUFFER_ULONG64** function reads a number of ULONG64 values from the specified register address into a buffer.

## Parameters

### `Register` [in]

A pointer to the register, which must be a mapped range in memory space.

### `Buffer` [out]

A pointer to a buffer into which an array of ULONG64 values is read.

### `Count` [in]

Specifies the number of ULONG64 values to be read into the buffer.

## Remarks

For more information, see [Reading and Writing to Device Registers in UMDF 1.x Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/reading-and-writing-to-device-registers-in-umdf-1-x-drivers).