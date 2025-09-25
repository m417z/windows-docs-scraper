# SetupDiSetDevicePropertyW function

## Description

The **SetupDiSetDeviceProperty** function sets a device instance property.

## Parameters

### `DeviceInfoSet` [in]

A handle to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets). This device information set contains a device information element that represents the device instance for which to set a device instance property.

### `DeviceInfoData` [in]

A pointer to the [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that identifies the device instance for which to set a device instance property.

### `PropertyKey` [in]

A pointer to a [DEVPROPKEY](https://learn.microsoft.com/windows-hardware/drivers/install/devpropkey) structure that represents the device property key of the device instance property to set.

### `PropertyType` [in]

A [DEVPROPTYPE](https://learn.microsoft.com/windows-hardware/drivers/install/property-data-type-identifiers)-typed value that represents the property-data-type identifier for the device instance property. For more information, see the **Remarks** section later in this topic.

### `PropertyBuffer` [in, optional]

A pointer to a buffer that contains the device instance property value. If the property is being deleted or set to a **NULL** value, this pointer must be **NULL**, and *PropertyBufferSize* must be set to zero.

### `PropertyBufferSize` [in]

The size, in bytes, of the *PropertyBuffer* buffer. If *PropertyBuffer*  is **NULL**, *PropertyBufferSize* must be set to zero.

### `Flags` [in]

This parameter must be set to zero.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE**, and the logged error can be retrieved by calling [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following table includes some of the more common error codes that this function might log.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_FLAGS** | The value of *Flags* is not zero. |
| **ERROR_INVALID_HANDLE** | The device information set that is specified by *DevInfoSet* is not valid. |
| **ERROR_INVALID_PARAMETER** | A supplied parameter is not valid. One possibility is that the device information element is not valid. |
| **ERROR_INVALID_REG_PROPERTY** | The property key that is supplied by *PropertyKey* is not valid or the property is not writable. |
| **ERROR_INVALID_DATA** | The property-data-type identifier that is supplied by *PropertyType*, or the property value that is supplied by *PropertyBuffer,* is not valid. |
| **ERROR_INVALID_USER_BUFFER** | A user buffer is not valid. One possibility is that *PropertyBuffer* is **NULL**, and *PropertyBufferSize* is not zero. |
| **ERROR_NO_SUCH_DEVINST** | The device instance that is specified by *DevInfoData* does not exist. |
| **ERROR_INSUFFICIENT_BUFFER** | An internal data buffer that was passed to a system call was too small. |
| **ERROR_NOT_ENOUGH_MEMORY** | There was not enough system memory available to complete the operation. |
| **ERROR_NOT_FOUND** | An unspecified internal element was not found. One possibility is that the property to be deleted does not exist. |
| **ERROR_ACCESS_DENIED** | The caller does not have Administrator privileges. |

## Remarks

**SetupDiSetDeviceProperty** is part of the [unified device property model](https://learn.microsoft.com/windows-hardware/drivers/install/unified-device-property-model--windows-vista-and-later-).

SetupAPI supports only a Unicode version of **SetupDiSetDeviceProperty**.

A caller of **SetupDiSetDeviceProperty** must be a member of the Administrators group to set a device instance property.

**SetupDiSetDeviceProperty** enforces requirements on the property-data-type identifier and the property value.

To obtain the device property keys for the instance device properties that are set for a device, call [SetupDiGetDevicePropertyKeys](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdevicepropertykeys).

To retrieve a device instance property, call [SetupDiGetDeviceProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdevicepropertyw).

## See also

[SetupDiGetDeviceProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdevicepropertyw)

[SetupDiGetDevicePropertyKeys](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdevicepropertykeys)