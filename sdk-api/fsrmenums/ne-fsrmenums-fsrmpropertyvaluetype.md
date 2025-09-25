# FsrmPropertyValueType enumeration

## Description

Enumerates the type of the value being assigned to an FSRM property in a property
condition.

## Constants

### `FsrmPropertyValueType_Undefined:0`

The type assigned to the property value is not defined.

### `FsrmPropertyValueType_Literal:1`

The type assigned to the property value is one or more literal values.

### `FsrmPropertyValueType_DateOffset:2`

The type assigned to the property value is a date expression containing a date variable and an optional
date offset.

## See also

[FSRM Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-enumerations)

[IFsrmFileConditionProperty.ValueType](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfileconditionproperty-get_valuetype)