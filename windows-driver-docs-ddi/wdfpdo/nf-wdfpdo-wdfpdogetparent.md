# WdfPdoGetParent function

## Description

[Applies to KMDF only]

The **WdfPdoGetParent** method returns a handle to the framework device object that represents the parent device of a specified device.

## Parameters

### `Device` [in]

A handle to a framework device object that represents the device's physical device object (PDO).

## Return value

The method returns a handle to the framework device object that represents the specified device's parent, or **NULL** if the *Device* value does not represent a PDO.

A system bug check occurs if the driver supplies an invalid object handle.