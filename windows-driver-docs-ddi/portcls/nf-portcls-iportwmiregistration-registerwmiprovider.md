# IPortWMIRegistration::RegisterWMIProvider

## Description

The `RegisterWMIProvider` method registers the [Event Tracing for Windows](https://learn.microsoft.com/windows-hardware/test/wpt/event-tracing-for-windows) (ETW) capability of the miniport driver with PortCls.

## Parameters

### `unnamedParam1` [in]

**MiniportWmiContext** - Specifies a pointer to a [WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmilib_context) structure that provides registration information for a driver's data blocks and event blocks.

### `unnamedParam2` [in]

**pDeviceObject** - Specifies a pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)  structure that represents the functional device object of the adapter driver.

## Return value

The `RegisterWMIProvider` method returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error code.

## Remarks

For more information about ETW, see [Improve Debugging And Performance Tuning With ETW](https://learn.microsoft.com/archive/msdn-magazine/2007/april/event-tracing-improve-debugging-and-performance-tuning-with-etw).

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[Event Tracing for Windows](https://learn.microsoft.com/windows-hardware/test/wpt/event-tracing-for-windows)

[IPortWMIRegistration](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwmiregistration)

[Improve Debugging And Performance Tuning With ETW](https://learn.microsoft.com/archive/msdn-magazine/2007/april/event-tracing-improve-debugging-and-performance-tuning-with-etw)

[WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/ns-wmilib-_wmilib_context)