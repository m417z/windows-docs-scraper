# tagWpdAttributeForm enumeration

## Description

The **WpdAttributeForm** enumeration type describes how a property stores its values.

## Constants

### `WPD_PROPERTY_ATTRIBUTE_FORM_UNSPECIFIED`

The form of the property's data was not specified.

### `WPD_PROPERTY_ATTRIBUTE_FORM_RANGE`

The value is expressed as a range of values, with a minimum and a maximum.

### `WPD_PROPERTY_ATTRIBUTE_FORM_ENUMERATION`

The property has a series of individual values.

### `WPD_PROPERTY_ATTRIBUTE_FORM_REGULAR_EXPRESSION`

The property value is a regular expression, not a literal expression.

### `WPD_PROPERTY_ATTRIBUTE_FORM_OBJECT_IDENTIFIER`

The property value is an object identifier.

## Remarks

This enumeration is used by the [WPD_PROPERTY_ATTRIBUTE_FORM](https://learn.microsoft.com/windows/desktop/wpd_sdk/attributes) property to describe how a property's data is stored.

## See also

[Structures and Enumeration Types](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff597672(v=vs.85))