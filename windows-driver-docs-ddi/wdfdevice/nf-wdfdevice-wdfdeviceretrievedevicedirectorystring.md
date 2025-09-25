# WdfDeviceRetrieveDeviceDirectoryString function

## Description

[Applies to UMDF only]

**WdfDeviceRetrieveDeviceDirectoryString** provides a path to a location on disk that can be used to persist information across reboots.

## Parameters

### `Device` [_In_]

A handle to a framework device object.

### `String` [_In_]

A handle to a [framework string object](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-string-objects). The framework will assign the directory path to the string object on successful return.

## Return value

This function returns NTSTATUS.
**WdfDeviceRetrieveDeviceDirectoryString** returns STATUS_SUCCESS if the operation succeeds.

## Remarks

UMDF only. KMDF drivers should use [**IoGetDeviceDirectory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdevicedirectory).

## See also

For info about string objects, see [Using String Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-string-objects).