# STORAGE_SET_TYPE enumeration

## Description

STORAGE_SET_TYPE describes the type of set operation that is being performed via an [IOCTL_STORAGE_SET_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_set_property) IOCTL.

## Constants

### `PropertyStandardSet`

Use **PropertyStandardSet** to change the value of a property.

### `PropertyExistsSet`

Use **PropertyExistsSet** to test whether a property is supported.

### `PropertySetMaxDefined`

Do not use.

## Remarks

**STORAGE_SET_TYPE** is a member of the [STORAGE_PROPERTY_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_property_set) structure, which describes the details of the property set associated with an IOCTL_STORAGE_SET_PROPERTY IOCTL.

## See also

[IOCTL_STORAGE_SET_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_set_property)

[STORAGE_PROPERTY_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_property_set)