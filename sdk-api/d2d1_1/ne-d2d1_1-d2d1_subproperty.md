# D2D1_SUBPROPERTY enumeration

## Description

Specifies the indices of the system sub-properties that may be present in any property.

## Constants

### `D2D1_SUBPROPERTY_DISPLAYNAME:0x80000000`

The name for the parent property.

### `D2D1_SUBPROPERTY_ISREADONLY:0x80000001`

A Boolean indicating whether the parent property is writable.

### `D2D1_SUBPROPERTY_MIN:0x80000002`

The minimum value that can be set to the parent property.

### `D2D1_SUBPROPERTY_MAX:0x80000003`

The maximum value that can be set to the parent property.

### `D2D1_SUBPROPERTY_DEFAULT:0x80000004`

The default value of the parent property.

### `D2D1_SUBPROPERTY_FIELDS:0x80000005`

An array of name/index pairs that indicate the possible values that can be set to the parent property.

### `D2D1_SUBPROPERTY_INDEX:0x80000006`

An index sub-property used by the elements of the **D2D1_SUBPROPERTY_FIELDS** array.

### `D2D1_SUBPROPERTY_FORCE_DWORD:0xffffffff`

## See also

[ID2D1Properties](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1properties)

[ID2D1Properties::GetPropertyName](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1properties-getpropertyname(uint32_pwstr_uint32))

[ID2D1Properties::GetPropertyNameLength](https://learn.microsoft.com/windows/win32/api/d2d1_1/nf-d2d1_1-id2d1properties-getpropertynamelength(u).md)

[ID2D1Properties::GetSubProperties](https://learn.microsoft.com/windows/win32/api/d2d1_1/nf-d2d1_1-id2d1properties-getsubproperties(u_id2d1properties).md)

[ID2D1Properties::GetType](https://learn.microsoft.com/windows/win32/api/d2d1_1/nf-d2d1_1-id2d1properties-gettype(u))

[ID2D1Properties::GetValue](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1properties-getvalue(uint32_byte_uint32))

[ID2D1Properties::GetValueSize](https://learn.microsoft.com/windows/win32/api/d2d1_1/nf-d2d1_1-id2d1properties-getvaluesize(u))

[ID2D1Properties::SetValue](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1properties-setvalue(uint32_constbyte_uint32))