# SetupDiGetClassPropertyExW function

## Description

The **SetupDiGetClassPropertyEx** function retrieves a class property for a [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes) or a [device interface class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-interface-classes) on a local or remote computer.

## Parameters

### `ClassGuid` [in]

A pointer to a GUID that identifies the device setup class or device interface class for which to retrieve a device property for the device class. For information about specifying the class type, see the *Flags* parameter.

### `PropertyKey` [in]

A pointer to a [DEVPROPKEY](https://learn.microsoft.com/windows-hardware/drivers/install/devpropkey) structure that represents the device property key of the requested device class property.

### `PropertyType` [out]

A pointer to a [DEVPROPTYPE](https://learn.microsoft.com/windows-hardware/drivers/install/property-data-type-identifiers)-typed variable that receives the property-data-type identifier of the requested device class property, where the property-data-type identifier is the bitwise OR between a base-data-type identifier and, if the base data type is modified, a property-data-type modifier.

### `PropertyBuffer` [out, optional]

A pointer to a buffer that receives the requested device class property. **SetupDiGetClassPropertyEx** retrieves the requested property value only if the buffer is large enough to hold all the property value data. The pointer can be **NULL**. If the pointer is set to **NULL** and *RequiredSize* is supplied, **SetupDiGetClassPropertyEx** returns the size of the device class property, in bytes, in **RequiredSize*.

### `PropertyBufferSize` [in]

The size, in bytes, of the *PropertyBuffer* buffer. If *PropertyBuffer* is set to **NULL**, *PropertyBufferSize* must be set to zero.

### `RequiredSize` [out, optional]

A pointer to a DWORD-typed variable that receives either the size, in bytes, of the device class property if the property is retrieved or the required buffer size if the buffer is not large enough. This pointer can be set to **NULL**.

### `Flags` [in]

One of the following values, which specifies whether the class is a device setup class or a device interface class:

#### DICLASSPROP_INSTALLER

*ClassGuid* specifies a device setup class. This flag cannot be used with DICLASSPROP_INTERFACE.

#### DICLASSPROP_INTERFACE

*ClassGuid* specifies a device interface class. This flag cannot be used with DICLASSPROP_INSTALLER.

### `MachineName` [in, optional]

A pointer to a NULL-terminated string that contains the UNC name, including the "\\" prefix, of a computer. The pointer can be set to **NULL**. If *MachineName* is **NULL**, **SetupDiGetClassPropertyEx** retrieves the requested device class property from the local computer.

> [!CAUTION]
> Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

### `Reserved`

This parameter must be set to **NULL**.

## Return value

**SetupDiGetClassPropertyEx** returns **TRUE** if it is successful. Otherwise, it returns **FALSE**, and the logged error can be retrieved by calling [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following table includes some of the more common error codes that this function might log.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_FLAGS** | The value of *Flags* is not zero. |
| **ERROR_INVALID_CLASS** | The device setup class that is specified by *ClassGuid* is not valid. This error can occur only if the DICLASSPROP_INSTALLER flag is specified. |
| **ERROR_INVALID_PARAMETER** | An unspecified parameter is not valid. |
| **ERROR_INVALID_REG_PROPERTY** | The property key that is supplied by *PropertyKey* is not valid. |
| **ERROR_INVALID_REFERENCE_STRING** | The device interface reference string is not valid. This error can be returned if the DICLASSPROP_INTERFACE flag is specified. |
| **ERROR_INVALID_DATA** | An unspecified internal data value was not valid. |
| **ERROR_INVALID_USER_BUFFER** | A user buffer is not valid. One possibility is that *PropertyBuffer* is **NULL**, and *PropertyBufferSize* is not zero. |
| **ERROR_INVALID_MACHINENAME** | The computer name that is specified by *MachineName* is not valid. |
| **ERROR_NO_SUCH_INTERFACE_CLASS** | The device interface class that is specified by *ClassGuid* does not exist. This error can occur only if the DICLASSPROP_INTERFACE flag is specified. |
| **ERROR_INSUFFICIENT_BUFFER** | An internal data buffer that was passed to a system call was too small. |
| **ERROR_NOT_ENOUGH_MEMORY** | There was not enough system memory available to complete the operation. |
| **ERROR_NOT_FOUND** | The requested device property does not exist. |
| **ERROR_ACCESS_DENIED** | The caller does not have Administrator privileges. |

## Remarks

**SetupDiGetClassPropertyEx** is part of the [unified device property model](https://learn.microsoft.com/windows-hardware/drivers/install/unified-device-property-model--windows-vista-and-later-).

SetupAPI supports only a Unicode version of **SetupDiGetClassPropertyEx**.

A caller of **SetupDiGetClassPropertyEx** must be a member of the Administrators group to set a device interface property.

To obtain the device property keys that represent the device properties that are set for a device class on a remote computer, call [SetupDiGetClassPropertyKeysEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclasspropertykeysexw).

To retrieve a device class property on a local computer, call [SetupDiGetClassProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclasspropertyw).

To set a device class property on a local computer, call [SetupDiSetClassProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetclasspropertyw)**,** and to set a device class property on a remote computer, call [SetupDiSetClassPropertyEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetclasspropertyexw).

## See also

[SetupDiGetClassProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclasspropertyw)

[SetupDiGetClassPropertyKeysEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclasspropertykeysexw)

[SetupDiSetClassProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetclasspropertyw)

[SetupDiSetClassPropertyEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetclasspropertyexw)