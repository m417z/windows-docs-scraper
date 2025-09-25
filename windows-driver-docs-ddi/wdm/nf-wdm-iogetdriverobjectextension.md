# IoGetDriverObjectExtension function

## Description

The **IoGetDriverObjectExtension** routine retrieves a previously allocated per-driver context area.

## Parameters

### `DriverObject` [in]

Specifies the driver object with which the context area is associated.

### `ClientIdentificationAddress` [in]

Specifies the unique identifier, provided when it was allocated, of the context area to be retrieved.

## Return value

**IoGetDriverObjectExtension** returns a pointer to the context area, if any or returns **NULL**.

## Remarks

Drivers call **IoGetDriverObjectExtension** to retrieve a pointer to a previously allocated extension area.

## See also

[IoAllocateDriverObjectExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocatedriverobjectextension)