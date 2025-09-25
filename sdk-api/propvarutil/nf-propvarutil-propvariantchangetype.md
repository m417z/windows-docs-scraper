# PropVariantChangeType function

## Description

Coerces a value stored as a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure to an equivalent value of a different variant type.

## Parameters

### `ppropvarDest` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

A pointer to a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure that, when this function returns successfully, receives the coerced value and its new type.

### `propvarSrc` [in]

Type: **REFPROPVARIANT**

A reference to the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure that contains the value expressed as its original type.

### `flags` [in]

Type: **PROPVAR_CHANGE_FLAGS**

Reserved, must be 0.

### `vt` [in]

Type: **[VARTYPE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms221127(v=vs.85))**

Specifies the new type for the value. See the tables below for recognized type names.

## Return value

Type: **HRESULT**

Returns **S_OK** if successful, or a standard COM error value otherwise. If the requested coercion is not possible, an error is returned.

## Remarks

Note that the source and destination [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structures must be separate structures. You cannot overwrite the source **PROPVARIANT** data with the new destination data; attempting to do so will result in an error.

[PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype) converts values between the following types as follows. Numbers refer to conditions explained after the tables.

|  | VT_LPWSTR | VT_BSTR | VT_BOOL | VT_FILETIME | VT_DATE | VT_CLSID |
| --- | --- | --- | --- | --- | --- | --- |
| VT_LPWSTR | Yes | Yes | Yes | Yes (2) | Yes (2) | Yes |
| VT_BSTR | Yes | Yes | Yes | Yes (2) | Yes (2) | Yes |
| VT_BOOL | Yes | Yes | Yes | No | No | No |
| VT_I2 | Yes | Yes | Yes | No | No | No |
| VT_I4 | Yes | Yes | Yes | No | No | No |
| VT_I8 | Yes | Yes | Yes | No | No | No |
| VT_UI2 | Yes | Yes | Yes | No | No | No |
| VT_UI4 | Yes | Yes | Yes | No | No | No |
| VT_UI8 | Yes | Yes | Yes | No | No | No |
| VT_R8 | Yes (3) | Yes (3) | Yes | No | No | No |
| VT_FILETIME | Yes (2) | Yes (2) | No | Yes | Yes | No |
| VT_DATE | Yes (2) | Yes (2) | No | Yes | Yes | No |
| VT_CLSID | Yes | Yes | No | No | No | Yes |

|  | VT_I2 | VT_I4 | VT_I8 | VT_UI2 | VT_UI4 | VT_UI8 | VT_R8 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| VT_LPWSTR | Yes | Yes | Yes | Yes | Yes | Yes | Yes (3) |
| VT_BSTR | Yes | Yes | Yes | Yes | Yes | Yes | Yes (3) |
| VT_BOOL | Yes | Yes | Yes | Yes | Yes | Yes | Yes |
| VT_I2 | Yes | Yes | Yes | Yes (1) | Yes (1) | Yes (1) | Yes (1) |
| VT_I4 | Yes (1) | Yes | Yes | Yes (1) | Yes (1) | Yes (1) | Yes (1) |
| VT_I8 | Yes (1) | Yes (1) | Yes | Yes (1) | Yes (1) | Yes (1) | Yes (1) |
| VT_UI2 | Yes (1) | Yes | Yes | Yes | Yes | Yes | Yes (1) |
| VT_UI4 | Yes (1) | Yes (1) | Yes | Yes (1) | Yes | Yes | Yes (1) |
| VT_UI8 | Yes (1) | Yes (1) | Yes (1) | Yes (1) | Yes (1) | Yes | Yes (1) |
| VT_R8 | Yes (1) | Yes (1) | Yes (1) | Yes (1) | Yes (1) | Yes (1) | Yes |
| VT_FILETIME | No | No | No | No | No | No | No |
| VT_DATE | No | No | No | No | No | No | No |
| VT_CLSID | No | No | No | No | No | No | No |

### Conditions

1. When converting between numeric types, out-of-range conversions fail. For instance, a negative signed value to an unsigned type, or a 4-byte unsigned value larger than 65535 to a 2-byte unsigned type.
2. When converting between strings and dates, a canonical string form is used rather than a localized or "human-readable" representation. The format is "yyyy/mm/dd:hh:mm:ss.fff" (year, month, date, hours, minutes, seconds, milliseconds). Note that this is less precision than is supported by the [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) type, but it should be sufficient for most purposes.
3. When converting between floating point numbers and strings, the current locale's decimal separator is used. Note that this might cause problems when these values are saved in files that are moved between different locales.

**Note** Additional types might be supported in the future.

Converting between vectors (**VT_VECTOR**) and arrays (**VT_ARRAY**) is supported in some cases. When it is supported, the count of elements must be the same in each. A single-valued vector can be converted to a non-vector value, but a multi-valued vector cannot be converted to a non-vector type.

Coercion between types is performed without respect to property-specific information. Property-specific coercions should be performed using [PSCoerceToCanonicalValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pscoercetocanonicalvalue). Additionally, if the string form of a value is needed for UI purposes, [PSFormatForDisplay](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psformatfordisplay) should be used to format the value according to locale- and property-specific information rather than using [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype) to coerce the value to a string.

#### Examples

The following code example, to be included as part of a larger program, demonstrates how to use [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype) to initialize a **VT_FILETIME** value from a string.

```cpp
PROPVARIANT propvarString = {0};

HRESULT hr = InitPropVariantFromString(L"2007/01/30:12:00:00.000", &propvarString);
if (SUCCEEDED(hr))
{
    PROPVARIANT propvarFiletime = {0};

    hr = PropVariantChangeType(&propvarFiletime, propvarString, 0, VT_FILETIME);
    if (SUCCEEDED(hr))
    {
        // propvarFiletime now contains the FILETIME representation
        // of 1/30/2007 12:00 PM
        PropVariantClear(&propvarFiletime);
    }
    PropVariantClear(&propvarString);
}
```