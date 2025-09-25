## Description

Contains information that represents a device object.

## Members

### `ObjectType`

A value from the [DEV_OBJECT_TYPE](https://learn.microsoft.com/windows/win32/api/devquerydef/ne-devquerydef-dev_object_type) enumeration that specifies the type of this device object.

### `pszObjectId`

The string that is the unique identifier for this particular object among objects of the same type.

### `cPropertyCount`

The count of [DEVPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/install/devproperty) structures pointed to by *pProperties*.

### `pProperties`

A pointer to an array of 0 or more **DEVPROPERTY** structures.

## Remarks

## See also