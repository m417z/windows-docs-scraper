# IPropertyDescription::GetPropertyType

## Description

Gets the variant type of the property.

## Parameters

### `pvartype` [out]

Type: **[VARTYPE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms221127(v=vs.85))***

When this method returns, contains a pointer to a [VARTYPE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms221127(v=vs.85)) that indicates the property type. If the property is multi-valued, the value pointed to is a **VT_VECTOR** mask (**VT_VECTOR** ORed to the **VARTYPE**. The following are the possible variant types.

#### VT_NULL

Value can be any type. No coercion is performed. If a type cannot be retrieved, this method retrieves a default value of VT_NULL.

#### VT_LPWSTR

String

#### VT_BOOL

Boolean

#### VT_UI1

Byte

#### VT_I2

16-bit signed integer

#### VT_UI2

16-bit unsigned integer

#### VT_I4

32-bit signed integer

#### VT_UI4

32-bit unsigned integer

#### VT_I8

64-bit signed integer

#### VT_UI8

64-bit unsigned integer

#### VT_R8

Double

#### VT_FILETIME

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure

#### VT_CLSID

GUID

#### VT_BLOB

Unspecified binary data

#### VT_UNKNOWN

Object that implements [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)

#### VT_STREAM

Object that implements [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)

## Return value

Type: **HRESULT**

This method always returns **S_OK**.

## Remarks

The information retrieved by this method comes from the *type* attribute of the [typeInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-typeinfo) element in the property's .propdesc file.

## See also

[IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription)

[Property Description Schema](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-entry)