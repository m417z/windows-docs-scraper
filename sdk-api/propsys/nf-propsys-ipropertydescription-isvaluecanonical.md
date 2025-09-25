# IPropertyDescription::IsValueCanonical

## Description

Gets a value that indicates whether a property is canonical according to the definition of the property description.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

A reference to a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure that contains the type and value of the property.

## Return value

Type: **HRESULT**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The value is canonical. |
| **S_FALSE** | The value is not canonical. |