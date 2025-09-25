# SetupDiGetDevicePropertyKeys function

## Description

The **SetupDiGetDevicePropertyKeys** function retrieves an array of the device property keys that represent the device properties that are set for a device instance.

## Parameters

### `DeviceInfoSet` [in]

A handle to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets). This device information set contains the device instance for which this function retrieves an array of device property keys. The property keys represent the device properties that are set for the device instance.

### `DeviceInfoData` [in]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that represents the device instance for which to retrieve the requested array of device property keys.

### `PropertyKeyArray` [out, optional]

A pointer to a buffer that receives an array of [DEVPROPKEY](https://learn.microsoft.com/windows-hardware/drivers/install/devpropkey)-typed values, where each value is a device property key that represents a device property that is set for the device instance. The pointer is optional and can be **NULL**. For more information, see the **Remarks** section later in this topic.

### `PropertyKeyCount` [in]

The size, in DEVPROPKEY-typed values, of the *PropertyKeyArray*  buffer*.* If *PropertyKeyArray* is set to **NULL**, *PropertyKeyCount* must be set to zero.

### `RequiredPropertyKeyCount` [out, optional]

A pointer to a DWORD-typed variable that receives the number of requested device property keys. The pointer is optional and can be set to **NULL**.

### `Flags` [in]

This parameter must be set to zero.

## Return value

**SetupDiGetDevicePropertyKeys** returns **TRUE** if it is successful. Otherwise, it returns **FALSE**, and the logged error can be retrieved by calling [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following table includes some of the more common error codes that this function might log.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_FLAGS** | The value of *Flags* is not zero. |
| **ERROR_INVALID_HANDLE** | The device information set that is specified by *DevInfoSet* is not valid. |
| **ERROR_INVALID_PARAMETER** | A supplied parameter is not valid. One possibility is that the device information element is not valid. |
| **ERROR_INVALID_DATA** | An internal data value is not valid. |
| **ERROR_INVALID_USER_BUFFER** | A user buffer is not valid. One possibility is that *PropertyKeyArray* is **NULL** and *PropertKeyCount* is not zero. |
| **ERROR_NO_SUCH_DEVINST** | The device instance that is specified by *DevInfoData* does not exist. |
| **ERROR_INSUFFICIENT_BUFFER** | The *PropertyKeyArray* buffer is too small to hold all the requested property keys. |
| **ERROR_NOT_ENOUGH_MEMORY** | There was not enough system memory available to complete the operation. |

## Remarks

**SetupDiGetDevicePropertyKeys** is part of the [unified device property model](https://learn.microsoft.com/windows-hardware/drivers/install/unified-device-property-model--windows-vista-and-later-).

If the *ProperKeyArray* buffer is not large enough to hold all the requested property keys, **SetupDiGetDevicePropertyKeys** does not retrieve any property keys and returns ERROR_INSUFFICIENT_BUFFER. If the caller supplied a *RequiredPropertyKeyCount* pointer, **SetupDiGetDevicePropertyKeys** sets the value of **RequiredPropertyKeyCount* to the required size, in DEVPROPKEY-typed values, of the *PropertyKeyArray*  buffer*.*

To retrieve a device instance property, call [SetupDiGetDeviceProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdevicepropertyw), and to set a device instance property, call [SetupDiSetDeviceProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetdevicepropertyw).

## See also

[SetupDiGetDeviceProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdevicepropertyw)

[SetupDiSetDeviceProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetdevicepropertyw)