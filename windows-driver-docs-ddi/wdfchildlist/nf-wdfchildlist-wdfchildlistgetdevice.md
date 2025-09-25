# WdfChildListGetDevice function

## Description

[Applies to KMDF only]

The **WdfChildListGetDevice** method returns a handle to the framework device object that represents the parent device of a specified child list.

## Parameters

### `ChildList` [in]

A handle to a framework child-list object.

## Return value

**WdfChildListGetDevice** returns a handle to a framework device object.

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about child lists, see [Dynamic Enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration).

#### Examples

The following code example obtains a handle to the device object that represents the parent device of a child list.

```cpp
WDFDEVICE parentDevice;

parentDevice = WdfChildListGetDevice(ChildList);
```