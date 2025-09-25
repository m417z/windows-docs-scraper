# SetupDiSetClassPropertyW function

## Description

The **SetupDiSetClassProperty** function sets a class property for a [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes) or a [device interface class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-interface-classes).

## Parameters

### `ClassGuid` [in]

A pointer to a GUID that identifies the device setup class or device interface class for which to set a device property. For information about how to specify the class type, see the *Flags* parameter.

### `PropertyKey` [in]

A pointer to a [DEVPROPKEY](https://learn.microsoft.com/windows-hardware/drivers/install/devpropkey) structure that represents the device property key of the device class property to set.

### `PropertyType` [in]

A [DEVPROPTYPE](https://learn.microsoft.com/windows-hardware/drivers/install/property-data-type-identifiers)-typed value that represents the property-data-type identifier for the device class property. For more information about the property-data-type identifier, see the **Remarks** section later in this topic.

### `PropertyBuffer` [in, optional]

A pointer to a buffer that contains the property value of the device class. If either the property or the data is being deleted, this pointer must be set to **NULL**, and *PropertyBufferSize* must be set to zero. For more information about property data, see the **Remarks** section later in this topic.

### `PropertyBufferSize` [in]

The size, in bytes, of the *PropertyBuffer* buffer. If *PropertyBuffer*  is set to **NULL**, *PropertyBufferSize* must be set to zero.

### `Flags` [in]

One of the following values, which specifies whether the class is a device setup class or a device interface class:

#### DICLASSPROP_INSTALLER

*ClassGuid* specifies a device setup class. This flag cannot be used with DICLASSPROP_INTERFACE.

#### DICLASSPROP_INTERFACE

*ClassGuid* specifies a device interface class. This flag cannot be used with DICLASSPROP_INSTALLER.

## Return value

**SetupDiSetClassProperty** returns **TRUE** if it is successful. Otherwise, it returns **FALSE**, and the logged error can be retrieved by calling [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following table includes some of the more common error codes that this function might log.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_FLAGS** | The value of *Flags* is invalid. |
| **ERROR_INVALID_CLASS** | The device setup class that is specified by *ClassGuid* is not valid. This error can occur only if the DICLASSPROP_INSTALLER flag is specified. |
| **ERROR_INVALID_REFERENCE_STRING** | The device interface reference string is not valid. This error can occur only if the DICLASSPROP_INTERFACE flag is specified. |
| **ERROR_INVALID_REG_PROPERTY** | The property key that is supplied by *PropertyKey* is not valid. |
| **ERROR_INVALID_DATA** | An unspecified internal data value was not valid. This error could be logged if the *ClassGuid* value is not a valid GUID or the property value is not consistent with the property type specified by *PropertyType.* |
| **ERROR_INVALID_USER_BUFFER** | A user buffer is not valid. One possibility is that *PropertyBuffer* is **NULL**, and *PropertyBufferSize* is not zero. |
| **ERROR_NO_SUCH_INTERFACE_CLASS** | The device interface class that is specified by *ClassGuid* does not exist. This error can occur only if the DICLASSPROP_INTERFACE flag is specified. |
| **ERROR_INSUFFICIENT_BUFFER** | An internal data buffer that was passed to a system call was too small. |
| **ERROR_NOT_ENOUGH_MEMORY** | There was not enough system memory available to complete the operation. |
| **ERROR_NOT_FOUND** | An unspecified item was not found. One possibility is that the property to be deleted does not exist. |
| **ERROR_ACCESS_DENIED** | The caller does not have Administrator privileges. |

## Remarks

**SetupDiSetClassProperty** is part of the [unified device property model](https://learn.microsoft.com/windows-hardware/drivers/install/unified-device-property-model--windows-vista-and-later-).

SetupAPI supports only a Unicode version of **SetupDiSetClassProperty**.

A caller of **SetupDiSetClassProperty** must be a member of the Administrators group to set a device interface property.

**SetupDiSetClassProperty** enforces requirements on the property-data-type identifier and the property value.

To obtain the device property keys that represent the device properties that are set for a device class on a local computer, call [SetupDiGetClassPropertyKeys](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclasspropertykeys).

To retrieve a device class property on a local computer, call [SetupDiGetClassProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclasspropertyw), and to retrieve a device class property on a remote computer, call [SetupDiGetClassPropertyEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclasspropertyexw).

To set a device class property on a remote computer, call [SetupDiSetClassPropertyEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetclasspropertyexw).

## See also

[SetupDiGetClassProperty](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclasspropertyw)

[SetupDiGetClassPropertyEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclasspropertyexw)

[SetupDiGetClassPropertyKeys](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclasspropertykeys)

[SetupDiSetClassPropertyEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetclasspropertyexw)