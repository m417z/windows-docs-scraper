# SetupDiGetDeviceInterfacePropertyW function

## Description

The **SetupDiGetDeviceInterfaceProperty** function retrieves a device property that is set for a device interface.

## Parameters

### `DeviceInfoSet` [in]

A handle to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains a device interface for which to retrieve a device interface property.

### `DeviceInterfaceData` [in]

A pointer to an [SP_DEVICE_INTERFACE_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_device_interface_data) structure that represents the device interface for which to retrieve a device interface property.

### `PropertyKey` [in]

A pointer to a [DEVPROPKEY](https://learn.microsoft.com/windows-hardware/drivers/install/devpropkey) structure that represents the device interface property key of the device interface property to retrieve.

### `PropertyType` [out]

A pointer to a [DEVPROPTYPE](https://learn.microsoft.com/windows-hardware/drivers/install/property-data-type-identifiers)-typed variable that receives the property-data-type identifier of the requested device interface property. The property-data-type identifier is a bitwise OR between a base-data-type identifier and, if the base-data type is modified, a property-data-type modifier.

### `PropertyBuffer` [out]

A pointer to a buffer that receives the requested device interface property. **SetupDiGetDeviceInterfaceProperty** retrieves the requested property only if the buffer is large enough to hold all the property value data. The pointer can be **NULL**. If the pointer is set to **NULL** and *RequiredSize* is supplied, **SetupDiGetDeviceInterfaceProperty** returns the size of the property, in bytes, in **RequiredSize*.

### `PropertyBufferSize` [in]

The size, in bytes, of the *PropertyBuffer* buffer. If *PropertyBuffer* is set to **NULL**, *PropertyBufferSize* must be set to zero.

### `RequiredSize` [out, optional]

A pointer to a DWORD-typed variable that receives the size, in bytes, of either the device interface property if the property is retrieved or the required buffer size, if the buffer is not large enough. This pointer can be set to **NULL**.

### `Flags` [in]

This parameter must be set to zero.

## Return value

**SetupDiGetDeviceInterfaceProperty** returns **TRUE** if it is successful. Otherwise, it returns **FALSE**, and the logged error can be retrieved by calling [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following table includes some of the more common error codes that this function might log. Other error codes can be set by the device installer functions that are called by this API.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_FLAGS** | The value of *Flags* is not zero. |
| **ERROR_INVALID_HANDLE** | The device information set that is specified by *DevInfoSet* is not valid. |
| **ERROR_INVALID_PARAMETER** | A supplied parameter is not valid. One possibility is that the device interface that is specified by *DeviceInterfaceData* is not valid. |
| **ERROR_INVALID_REG_PROPERTY** | The property key that is supplied by *PropertyKey* is not valid. |
| **ERROR_INVALID_DATA** | An unspecified internal data value was not valid. |
| **ERROR_INVALID_USER_BUFFER** | A user buffer is not valid. One possibility is that *PropertyBuffer* is **NULL**, and *PropertyBufferSize* is not zero. |
| **ERROR_NO_SUCH_DEVICE_INTERFACE** | The device interface that is specified by *DeviceInterfaceData* does not exist. |
| **ERROR_INSUFFICIENT_BUFFER** | The *PropertyBuffer* buffer is not large enough to hold the property value, or an internal data buffer that was passed to a system call was too small. |
| **ERROR_NOT_ENOUGH_MEMORY** | There was not enough system memory available to complete the operation. |
| **ERROR_NOT_FOUND** | The requested device property does not exist. |
| **ERROR_ACCESS_DENIED** | The caller does not have Administrator privileges. |

## Remarks

**SetupDiGetDeviceInterfaceProperty** is part of the [unified device property model](https://learn.microsoft.com/windows-hardware/drivers/install/unified-device-property-model--windows-vista-and-later-).

SetupAPI supports only a Unicode version of **SetupDiGetDeviceInterfaceProperty**.

A caller of **SetupDiGetDeviceInterfaceProperty** must be a member of the Administrators group to set a device interface property.

To obtain the device property keys that represent the device properties that are set for a device interface, call [SetupDiGetDeviceInterfacePropertyKeys](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinterfacepropertykeys).

To set a device interface property, call [SetupDiSetDeviceInterfaceProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetdeviceinterfacepropertyw).

## See also

[SetupDiGetDeviceInterfacePropertyKeys](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinterfacepropertykeys)

[SetupDiSetDeviceInterfaceProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetdeviceinterfacepropertyw)