# WpdAttributeForm enumeration

The **WpdAttributeForm** enumeration type describes how a property stores its values.

## Constants

**WPD\_PROPERTY\_ATTRIBUTE\_FORM\_UNSPECIFIED**

The form of the property's data is not specified.

**WPD\_PROPERTY\_ATTRIBUTE\_FORM\_RANGE**

The value is expressed as a range of values, with a minimum and a maximum.

**WPD\_PROPERTY\_ATTRIBUTE\_FORM\_ENUMERATION**

The property has a series of individual values.

**WPD\_PROPERTY\_ATTRIBUTE\_FORM\_REGULAR\_EXPRESSION**

The property value is a regular expression, not a literal expression.

**WPD\_PROPERTY\_ATTRIBUTE\_FORM\_OJBECT\_IDENTIFIER**

The property value represents an object identifier.

## Remarks

This enumeration is used by the [WPD\_PROPERTY\_ATTRIBUTE\_FORM](https://learn.microsoft.com/windows/win32/wpd_sdk/attributes) property to describe how a property's data is stored.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------------|
| Header<br> | PortableDevice.h |

## See also

[**Structures and Enumeration Types**](https://learn.microsoft.com/windows/win32/wpd_sdk/structures-and-enumeration-types)

