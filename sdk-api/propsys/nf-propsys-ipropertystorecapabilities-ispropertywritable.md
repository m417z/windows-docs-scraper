# IPropertyStoreCapabilities::IsPropertyWritable

## Description

Queries whether the property handler allows a specific property to be edited in the UI by the user.

## Parameters

### `key` [in]

Type: **REFPROPERTYKEY**

A reference to [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure that represents the property being queried.

## Return value

Type: **HRESULT**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The property can be edited and stored by the handler. |
| **S_FALSE** | The property cannot be edited. |

## Remarks

The Shell disables the editing of controls by the user as appropriate through this method. A handler that does not support [IPropertyStoreCapabilities](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystorecapabilities) is assumed to support writing of any property.