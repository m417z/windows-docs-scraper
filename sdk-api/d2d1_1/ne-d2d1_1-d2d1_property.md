# D2D1_PROPERTY enumeration

## Description

Specifies the indices of the system properties present on the [ID2D1Properties](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1properties) interface for an [ID2D1Effect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1effect).

## Constants

### `D2D1_PROPERTY_CLSID:0x80000000`

The CLSID of the effect.

### `D2D1_PROPERTY_DISPLAYNAME:0x80000001`

The name of the effect.

### `D2D1_PROPERTY_AUTHOR:0x80000002`

The author of the effect.

### `D2D1_PROPERTY_CATEGORY:0x80000003`

The category of the effect.

### `D2D1_PROPERTY_DESCRIPTION:0x80000004`

The description of the effect.

### `D2D1_PROPERTY_INPUTS:0x80000005`

The names of the effect's inputs.

### `D2D1_PROPERTY_CACHED:0x80000006`

The output of the effect should be cached.

### `D2D1_PROPERTY_PRECISION:0x80000007`

The buffer precision of the effect output.

### `D2D1_PROPERTY_MIN_INPUTS:0x80000008`

The minimum number of inputs supported by the effect.

### `D2D1_PROPERTY_MAX_INPUTS:0x80000009`

The maximum number of inputs supported by the effect.

### `D2D1_PROPERTY_FORCE_DWORD:0xffffffff`

## Remarks

Under normal circumstances the minimum and maximum number of inputs to the effect are the same. If the effect supports a variable number of inputs, the [ID2D1Effect::SetNumberOfInputs](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1effect-setinputcount) method can be used to choose the number that the application will enable.

## See also

[ID2D1Properties](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1properties)

[ID2D1Properties::GetPropertyName](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1properties-getpropertyname(uint32_pwstr_uint32))

[ID2D1Properties::GetPropertyNameLength](https://learn.microsoft.com/windows/win32/api/d2d1_1/nf-d2d1_1-id2d1properties-getpropertynamelength(u).md)

[ID2D1Properties::GetSubProperties](https://learn.microsoft.com/windows/win32/api/d2d1_1/nf-d2d1_1-id2d1properties-getsubproperties(u_id2d1properties).md)

[ID2D1Properties::GetType](https://learn.microsoft.com/windows/win32/api/d2d1_1/nf-d2d1_1-id2d1properties-gettype(u))

[ID2D1Properties::GetValue](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1properties-getvalue(uint32_byte_uint32))

[ID2D1Properties::GetValueSize](https://learn.microsoft.com/windows/win32/api/d2d1_1/nf-d2d1_1-id2d1properties-getvaluesize(u))

[ID2D1Properties::SetValue](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1properties-setvalue(uint32_constbyte_uint32))