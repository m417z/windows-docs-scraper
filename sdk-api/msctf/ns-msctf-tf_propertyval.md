# TF_PROPERTYVAL structure

## Description

The **TF_PROPERTYVAL** structure contains property value data. This structure is used with the [IEnumTfPropertyValue::Next](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-ienumtfpropertyvalue-next) method.

## Members

### `guidId`

A **GUID** that identifies the property type. This can be a custom identifier or one of the [predefined property identifiers](https://learn.microsoft.com/windows/desktop/TSF/predefined-properties).

### `varValue`

A **VARIANT** that contains the value of the property specified by **guidId**. The user must know the type and format of this data.

## See also

[IEnumTfPropertyValue::Next](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-ienumtfpropertyvalue-next)

[Predefined Properties](https://learn.microsoft.com/windows/desktop/TSF/predefined-properties)