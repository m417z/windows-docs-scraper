# WdfChildListUpdateAllChildDescriptionsAsPresent function

## Description

[Applies to KMDF only]

The **WdfChildListUpdateAllChildDescriptionsAsPresent** method informs the framework that all of the child devices in a specified child list are plugged in and available.

## Parameters

### `ChildList` [in]

A handle to a child list object.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

The **WdfChildListUpdateAllChildDescriptionsAsPresent** method is available in version 1.0 and later versions of KMDF.

For more information about child lists, see [Dynamic Enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration).

#### Examples

The following code example informs the framework that all of the devices that a device list represents are plugged in and available.

```cpp
WdfChildListUpdateAllChildDescriptionsAsPresent(DeviceList);
```