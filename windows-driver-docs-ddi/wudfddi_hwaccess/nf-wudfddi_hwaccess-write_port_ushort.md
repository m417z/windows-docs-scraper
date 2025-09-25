# WRITE_PORT_USHORT function (wudfddi_hwaccess.h)

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **WRITE_PORT_USHORT** function writes a USHORT value to the specified port address.

## Parameters

### `pDevice` [in]

Specifies a pointer to the [IWDFDevice3](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice3) interface for the device object of the device to access.

### `Port` [in]

A pointer to the port, which must be a mapped memory range in I/O space.

### `Value` [in]

Specifies a USHORT value to be written to the port.

## Remarks

For more information, see [Reading and Writing to Device Registers in UMDF 1.x Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/reading-and-writing-to-device-registers-in-umdf-1-x-drivers).