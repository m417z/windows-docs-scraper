# SetupDiSetDeviceInterfacePropertyW function

## Description

The **SetupDiSetDeviceInterfaceProperty** function sets a device property of a device interface.

## Parameters

### `DeviceInfoSet` [in]

A handle to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains the device interface for which to set a device interface property.

### `DeviceInterfaceData` [in]

A pointer to an [SP_DEVICE_INTERFACE_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_device_interface_data) structure that represents the device interface for which to set a device interface property.

### `PropertyKey` [in]

A pointer to a [DEVPROPKEY](https://learn.microsoft.com/windows-hardware/drivers/install/devpropkey) structure that represents the device property key of the device interface property to set.

### `PropertyType` [in]

A [DEVPROPTYPE](https://learn.microsoft.com/windows-hardware/drivers/install/property-data-type-identifiers)-typed value that represents the property-data-type identifier of the device interface property to set. For more information about the property-data-type identifier, see the **Remarks** section later in this topic.

### `PropertyBuffer` [in, optional]

A pointer to a buffer that contains the device interface property value. If either the property or the interface value is being deleted, this pointer must be set to **NULL**, and *PropertyBufferSize* must be set to zero. For more information about property value data, see the **Remarks** section later in this topic.

### `PropertyBufferSize` [in]

The size, in bytes, of the *PropertyBuffer* buffer. The property buffer size must be consistent with the property-data-type identifier that is supplied by *PropertyType*. If *PropertyBuffer*  is set to **NULL**, *PropertyBufferSize* must be set to zero.

### `Flags` [in]

Must be set to zero.

## Return value

**SetupDiSetDeviceInterfaceProperty** returns **TRUE** if it is successful. Otherwise, this function returns **FALSE**, and the logged error can be retrieved by calling [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following table includes some of the more common error codes that this function might log.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_FLAGS** | The value of *Flags* is not zero. |
| **ERROR_INVALID_HANDLE** | The device information set that is specified by *DevInfoSet* is not valid. |
| **ERROR_INVALID_PARAMETER** | A supplied parameter is not valid. One possibility is that the device interface specified by *DeviceInterfaceData* is not valid. |
| **ERROR_INVALID_REG_PROPERTY** | The property key that is supplied by *PropertyKey* is not valid. |
| **ERROR_INVALID_DATA** | An unspecified data value was not valid. This error could be logged if either the symbolic link name of the device interface is not valid or the property-data-type identifier is not valid. |
| **ERROR_INVALID_USER_BUFFER** | A user buffer is not valid. One possibility is that *PropertyBuffer* is **NULL**, and *PropertBufferSize* is not zero. |
| **ERROR_NO_SUCH_DEVICE_INTERFACE** | The device interface that is specified by *DeviceInterfaceData* does not exist. |
| **ERROR_INSUFFICIENT_BUFFER** | An internal data buffer that was passed to a system call was too small. |
| **ERROR_NOT_ENOUGH_MEMORY** | There was not enough system memory available to complete the operation. |
| **ERROR_NOT_FOUND** | An unspecified internal element was not found. One possibility is that a property to be deleted does not exist. |
| **ERROR_ACCESS_DENIED** | The caller does not have Administrator privileges. |

## Remarks

**SetupDiSetDeviceInterfaceProperty** is part of the [unified device property model](https://learn.microsoft.com/windows-hardware/drivers/install/unified-device-property-model--windows-vista-and-later-).

SetupAPI supports only a Unicode version of **SetupDiSetDeviceInterfaceProperty**.

A caller of **SetupDiSetDeviceInterfaceProperty** must be a member of the Administrators group to set a device interface property.

**SetupDiSetDeviceInterfaceProperty** enforces requirements on the property-data-type identifier and the property value.

To obtain the device property keys that represent the device properties that are set for a device interface, call [SetupDiGetDeviceInterfacePropertyKeys](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinterfacepropertykeys).

To retrieve a device interface property, call [SetupDiGetDeviceInterfaceProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinterfacepropertyw).

## See also

[SetupDiGetDeviceInterfaceProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinterfacepropertyw)

[SetupDiGetDeviceInterfacePropertyKeys](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinterfacepropertykeys)