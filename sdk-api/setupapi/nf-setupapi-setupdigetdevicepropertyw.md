# SetupDiGetDevicePropertyW function

## Description

The **SetupDiGetDeviceProperty** function retrieves a device instance property.

## Parameters

### `DeviceInfoSet` [in]

A handle to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains a device instance for which to retrieve a device instance property.

### `DeviceInfoData` [in]

A pointer to the [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that represents the device instance for which to retrieve a device instance property.

### `PropertyKey` [in]

A pointer to a [DEVPROPKEY](https://learn.microsoft.com/windows-hardware/drivers/install/devpropkey) structure that represents the device property key of the requested device instance property.

### `PropertyType` [out]

A pointer to a [DEVPROPTYPE](https://learn.microsoft.com/windows-hardware/drivers/install/property-data-type-identifiers)-typed variable that receives the property-data-type identifier of the requested device instance property, where the property-data-type identifier is the bitwise OR between a base-data-type identifier and, if the base-data type is modified, a property-data-type modifier.

### `PropertyBuffer` [out, optional]

A pointer to a buffer that receives the requested device instance property. **SetupDiGetDeviceProperty** retrieves the requested property only if the buffer is large enough to hold all the property value data. The pointer can be **NULL**. If the pointer is set to **NULL** and *RequiredSize* is supplied, **SetupDiGetDeviceProperty** returns the size of the property, in bytes, in **RequiredSize*.

### `PropertyBufferSize` [in]

The size, in bytes, of the *PropertyBuffer* buffer. If *PropertyBuffer* is set to **NULL**, *PropertyBufferSize* must be set to zero.

### `RequiredSize` [out, optional]

A pointer to a DWORD-typed variable that receives the size, in bytes, of either the device instance property if the property is retrieved or the required buffer size if the buffer is not large enough. This pointer can be set to **NULL**.

### `Flags` [in]

This parameter must be set to zero.

## Return value

**SetupDiGetDeviceProperty** returns **TRUE** if it is successful. Otherwise, it returns **FALSE**, and the logged error can be retrieved by calling [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following table includes some of the more common error codes that this function might log.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_FLAGS** | The value of *Flags* is not zero. |
| **ERROR_INVALID_HANDLE** | The device information set that is specified by *DevInfoSet* is not valid. |
| **ERROR_INVALID_PARAMETER** | A supplied parameter is not valid. One possibility is that the device information element is not valid. |
| **ERROR_INVALID_REG_PROPERTY** | The property key that is supplied by *PropertyKey* is not valid. |
| **ERROR_INVALID_DATA** | An unspecified internal data value was not valid. |
| **ERROR_INVALID_USER_BUFFER** | A user buffer is not valid. One possibility is that *PropertyBuffer* is **NULL** and *PropertBufferSize* is not zero. |
| **ERROR_NO_SUCH_DEVINST** | The device instance that is specified by *DevInfoData* does not exist. |
| **ERROR_INSUFFICIENT_BUFFER** | The *PropertyBuffer* buffer is too small to hold the requested property value, or an internal data buffer that was passed to a system call was too small. |
| **ERROR_NOT_ENOUGH_MEMORY** | There was not enough system memory available to complete the operation. |
| **ERROR_NOT_FOUND** | The requested device property does not exist. |
| **ERROR_ACCESS_DENIED** | The caller does not have Administrator privileges. |

## Remarks

**SetupDiGetDeviceProperty** is part of the [unified device property model](https://learn.microsoft.com/windows-hardware/drivers/install/unified-device-property-model--windows-vista-and-later-).

SetupAPI supports only a Unicode version of **SetupDiGetDeviceProperty**.

To obtain the device property keys that represent the device properties that are set for a device instance, call [SetupDiGetDevicePropertyKeys](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdevicepropertykeys).

To set a device instance property, call [SetupDiSetDeviceProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetdevicepropertyw).

## See also

[SetupDiGetDevicePropertyKeys](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdevicepropertykeys)

[SetupDiSetDeviceProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetdevicepropertyw)