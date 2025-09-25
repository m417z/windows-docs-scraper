# IPortWMIRegistration::UnregisterWMIProvider

## Description

The `UnregisterWMIProvider` method unregisters the [Event Tracing for Windows](https://learn.microsoft.com/windows-hardware/test/wpt/event-tracing-for-windows) (ETW) interface that was previously registered with a call to the RegisterWMIProvider method. The unregistration disables the ETW registration with PortCls.

## Parameters

### `unnamedParam1` [in]

**pDeviceObject** - Specifies a pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)  structure that represents the functional device object of the adapter driver.

## Return value

The `UnregisterWMIProvider` method returns STATUS_SUCCESS if the call is successful. Otherwise, it returns the appropriate error message.

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[Event Tracing for Windows](https://learn.microsoft.com/windows-hardware/test/wpt/event-tracing-for-windows)

[IPortWMIRegistration](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwmiregistration)