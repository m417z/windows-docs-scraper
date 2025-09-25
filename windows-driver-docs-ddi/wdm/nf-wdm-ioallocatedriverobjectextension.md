# IoAllocateDriverObjectExtension function

## Description

The **IoAllocateDriverObjectExtension** routine allocates a per-driver context area, called a [driver object extension](https://learn.microsoft.com/windows-hardware/drivers/), and assigns a unique identifier to it.

## Parameters

### `DriverObject` [in]

Pointer to a driver object to which the context area will be associated.

### `ClientIdentificationAddress` [in]

Specifies a unique identifier for the context area to be allocated.

### `DriverObjectExtensionSize` [in]

Specifies the length, in bytes, of the context area to be allocated.

### `DriverObjectExtension` [out]

Pointer to, on completion, the allocated context area.

## Return value

**IoAllocateDriverObjectExtension** returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | Indicates that the routine allocated an extension of the requested size. |
| **STATUS_INSUFFICIENT_RESOURCES** | Indicates that the memory could not be allocated for the driver object extension. |
| **STATUS_OBJECT_NAME_COLLISION** | Indicates that a driver object extension with the given *ClientIdentificationAddress* already exists. |

## Remarks

Memory allocated by the system for the driver object extension is resident storage and is accessible from any IRQL. The allocated storage is automatically freed by the I/O manager when the driver object is deleted.

Callers of this routine must provide a unique identifier for *ClientIdentificationAddress*. To retrieve a pointer to the context area, a caller passes the *ClientIdentificationAddress* to [IoGetDriverObjectExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdriverobjectextension).

## See also

[IoGetDriverObjectExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdriverobjectextension)