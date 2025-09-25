# ISensorDriver::OnProcessWpdMessage

## Description

The [ISensorDriver::OnProcessWpdMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensordriver-onprocesswpdmessage) method handles Windows Portable Device (WPD) commands that the [ISensorClassExtension::ProcessIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensorclassextension-processiocontrol) method does not handle internally.

## Parameters

### `pUnkPortableDeviceValuesParams`

A pointer to the IUnknown interface that supports the IPortableDeviceValues interface. The object that is associated with this IUnknown interface contains the parameters for the WPD command. For more information, see IPortableDeviceValues in Windows Portable Devices.

### `pUnkPortableDeviceValuesResults`

A pointer to the IUnknown interface that supports the IPortableDeviceValues interface. The object that is associated with this IUnknown interface stores the results for the WPD command.

## Return value

If the operation succeeds, this method returns S_OK. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

This method enables you to extend the WPD commands and interfaces in a device-specific way.

## See also

[ISensorDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nn-sensorsclassextension-isensordriver)