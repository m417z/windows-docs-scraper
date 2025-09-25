# SetupDiGetClassPropertyKeys function

## Description

The **SetupDiGetClassPropertyKeys** function retrieves an array of the device property keys that represent the device properties that are set for a [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes) or a [device interface class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-interface-classes).

## Parameters

### `ClassGuid` [in]

A pointer to a GUID that represents a device setup class or a device interface class. **SetupDiGetClassPropertyKeys** retrieves an array of the device property keys that represent device properties that are set for the specified class. For information about specifying the class type, see the *Flags* parameter.

### `PropertyKeyArray` [out, optional]

A pointer to a buffer that receives an array of [DEVPROPKEY](https://learn.microsoft.com/windows-hardware/drivers/install/devpropkey)-typed values, where each value is a device property key that represents a device property that is set for the device class. The pointer is optional and can be **NULL**. For more information, see the **Remarks** section later in this topic.

### `PropertyKeyCount` [in]

The size, in DEVPROPKEY-typed values, of the *PropertyKeyArray* buffer. If *PropertyKeyArray* is set to **NULL**, *PropertyKeyCount* must be set to zero.

### `RequiredPropertyKeyCount` [out, optional]

A pointer to a DWORD-typed variable that receives the number of requested property keys. The parameter is optional and can be set to **NULL**.

### `Flags` [in]

One of the following values, which specifies whether to retrieve property keys for a device setup class or for a device interface class:

#### DICLASSPROP_INSTALLER

*ClassGuid* specifies a device setup class. This flag cannot be used with DICLASSPROP_INTERFACE.

#### DICLASSPROP_INTERFACE

*ClassGuid* specifies a device interface class. This flag cannot be used with DICLASSPROP_INSTALLER.

## Return value

**SetupDiGetClassPropertyKeys** returns **TRUE** if it is successful. Otherwise, it returns **FALSE**, and the logged error can be retrieved by calling [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following table includes some of the more common error codes that this function might log.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_FLAGS** | The value of *Flags* is not valid. |
| **ERROR_INVALID_CLASS** | If the DICLASSPROP_INSTALLER flag is specified, this error code indicates that the device setup class that is specified by *ClassGuid* does not exist. |
| **ERROR_INVALID_REFERENCE_STRING** | The reference string for the device interface that is specified by *ClassGuild* is not valid. This error can be returned if the DICLASSPROP_INTERFACE flag is specified. |
| **ERROR_INVALID_DATA** | An unspecified data value is not valid. One possibility is that the *ClassGuid* value is not valid. |
| **ERROR_INVALID_PARAMETER** | An unspecified parameter is not valid. |
| **ERROR_INVALID_USER_BUFFER** | A user buffer is not valid. One possibility is that *PropertyKeyArray* is **NULL**, and *PropertKeyCount* is not zero. |
| **ERROR_NO_SUCH_INTERFACE_CLASS** | If the DICLASSPROP_INTERFACE flag is specified, this error code indicates that the device interface class that is specified by *ClassGuid* does not exist. |
| **ERROR_INSUFFICENT_BUFFER** | The *PropertyKeyArray* buffer is not large enough to hold all the property keys, or an internal data buffer that was passed to a system call was too small. |
| **ERROR_NOT_ENOUGH_MEMORY** | There was not enough system memory available to complete the operation. |
| **ERROR_ACCESS_DENIED** | The caller does not have Administrator privileges. |

## Remarks

**SetupDiGetClassPropertyKeys** is part of the [unified device property model](https://learn.microsoft.com/windows-hardware/drivers/install/unified-device-property-model--windows-vista-and-later-).

A caller of **SetupDiGetClassPropertyKeys** must be a member of the Administrators group to retrieve device property keys for a device class.

If the *PropertyKeyArray* buffer is not large enough to hold all the requested property keys, **SetupDiGetClassPropertyKeys** does not retrieve any property keys and returns ERROR_INSUFFICIENT_BUFFER. If the caller supplied a *RequiredPropertyKeyCount* pointer, **SetupDiGetClassPropertyKeys** sets the value of **RequiredPropertyKeyCount* to the required size, in DEVPROPKEY-typed values, of the *PropertyKeyArray*  buffer*.*

To retrieve a device class property on a local computer, call [SetupDiGetClassProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclasspropertyw). To set a device class property on a local computer, call [SetupDiSetClassProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetclasspropertyw).

To retrieve the property keys for a device setup class or device interface class on a remote computer, call [SetupDiGetClassPropertyKeysEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclasspropertykeysexw).

## See also

[SetupDiGetClassProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclasspropertyw)

[SetupDiGetClassPropertyKeysEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclasspropertykeysexw)

[SetupDiSetClassProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetclasspropertyw)