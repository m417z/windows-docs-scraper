# PSCoerceToCanonicalValue function

## Description

Converts the value of a property to the canonical value, according to the property description.

## Parameters

### `key` [in]

Type: **REFPROPERTYKEY**

Reference to a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure that identifies the property whose value is to be coerced.

### `ppropvar` [in, out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

On entry, contains a pointer to a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure that contains the original value. When this function returns successfully, contains the canonical value.

## Return value

Type: **HRESULT**

Possible return values include the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. The property value specified by *ppropvar* is now in a canonical form. |
| **INPLACE_S_TRUNCATED** | The property value specified by *ppropvar* is now in a truncated, canonical form. |
| **E_INVALIDARG** | The *ppropvar* parameter is invalid. The [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure has been cleared. |
| **TYPE_E_TYPEMISMATCH** | Coercion from the value's type to the property description's type was not possible. The [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure has been cleared. |
| **Any other failure code** | Coercion from the value's type to the property description's type was not possible. The [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure has been cleared. |

## Remarks

This function is a wrapper around the system's implementation of [IPropertyDescription::CoerceToCanonicalValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertydescription-coercetocanonicalvalue).

Most property descriptions specify the type that their values are expected to use. For example, the property description for [System.Title](https://learn.microsoft.com/windows/desktop/properties/props-system-title) specifies that System.Title values should be of type VT_LPWSTR. This function coerces values to this type, and then coerces the result into a canonical form.

It is important to note that if this function fails, it will have already called [PropVariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/oe/oe-imimeallocator-propvariantclear) on the input [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure. Only if this function succeeds is the calling application responsible for calling **PropVariantClear** on *ppropvar* when the structure is no longer needed.

The coercion performed by this function is also performed by the property system during calls to [IPropertyStore::GetValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-getvalue) and [IPropertyStore::SetValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-setvalue). Applications can either depend on the property system to perform the coercions or can use this function to perform the coercion at a time of the application's choosing.

The coercion is performed in four steps, as follows:

1. The following values are converted to VT_EMPTY.
   * Values of type VT_NULL.
   * Values of type VT_LPWSTR, VT_BSTR, or VT_LPSTR whose pointer is **NULL**.
   * Values of type VT_LPWSTR, VT_BSTR, or VT_LPSTR that are empty or consist entirely of spaces.
   * Values of type VT_FILETIME prior to midnight 1601/01/02.
2. If the value is not of type VT_EMPTY after Step 1, it is converted to the type specified by the property description. The type of a property description can be obtained by calling [IPropertyDescription::GetPropertyType](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertydescription-getpropertytype). For information on how the property schema influences the type of a property description, see [typeInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-typeinfo). Conversions are performed as follows:
   * Values of type VT_LPWSTR, VT_BSTR, or VT_LPSTR are converted to VT_VECTOR | VT_LPWSTR using [InitPropVariantFromStringAsVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromstringasvector).
   * All other conversions are performed using [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype)
3. After Steps 2 and 3, the value is coerced into a canonical form based on its type. The canonical forms are summarized in the following table.

   | Value Type | Canonical Form |
   | --- | --- |
   | VT_EMPTY | Always canonical. |
   | VT_LPWSTR | * No leading or trailing spaces. The string is non-empty and non-**NULL**. For example, L"Alice".<br>* If this is a tree property (that is, if the [typeInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-typeinfo) element's *isTreeProperty* attribute is **TRUE**), then it must not have leading or trailing forward slashes (/), must not have spaces between the text and the forward slashes, and must not have two consecutive forward slashes(/). For example, L"Friend/Bob".<br>* Coercion removes unnecessary characters and results in VT_EMPTY if there was no content. |
   | VT_VECTOR \| VT_LPWSTR | * Each string in the vector must adhere to the rules for VT_LPWSTR listed above. In addition, the vector must have no duplicates and have no null pointers.<br>* If this is a tree property, then no value can be the ancestor of another value. For example, L"Friend" is an ancestor of L"Friend/Bob".<br>* If there is no content, coercion removes duplicate and ancestor characters and results in VT_EMPTY. |
4. If applicable, the value is checked against the property description type enumeration. The checks in the following table apply.

   | Enumeration Type | Value Type | Canonical Form |
   | --- | --- | --- |
   | Discrete or Ranged | VT_EMPTY | Always canonical |
   | Discrete | VT_LPWSTR | The string matches one of the enumerated strings allowed for the property. Comparisons are case-insensitive. If not, convert the value to VT_EMPTY. |
   | Discrete | Numeric | The number matches one of the enumerated values allowed for the property. If not, convert the value to VT_EMPTY. |
   | Discrete | VT_VECTOR \| VT_LPWSTR | Each string in the vector matches one of the enumerated strings allowed for the property. Comparisons are case-insensitive. If not, remove that string from the vector. If the resulting vector is empty, convert the value to VT_EMPTY. |
   | Discrete | VT_VECTOR \| Numeric | Each number in the vector matches one of the enumerated values allowed for the property. If not, remove that number from the vector. If the resulting vector is empty, convert the value to VT_EMPTY. |
   | Ranged | VT_LPWSTR | The string exists in the range allowed for the property. Comparisons are case-sensitive. If not, convert the value to VT_EMPTY. |
   | Ranged | Numeric | The number exists in the range allowed for the property. If not, convert the value to VT_EMPTY. |
   | Ranged | VT_VECTOR \| VT_LPWSTR | Each string in the vector exists in the range allowed for the property. Comparisons are case-sensitive. If not, remove that string from the vector. If the resulting vector is empty, convert the value to VT_EMPTY. |
   | Ranged | VT_VECTOR \| Numeric | Each number in the vector exists in the range allowed for the property. If not, remove that number from the vector. If the resulting vector is empty, convert the value to VT_EMPTY. |

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PSCoerceToCanonicalValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pscoercetocanonicalvalue) to coerce a value to the type required for PKEY_Keywords.

```cpp
// PROPVARIANT propvar;
// Assume variable propvar is initialized and valid.

HRESULT hr = PSCoerceToCanonicalValue(PKEY_Keywords, &propvar);

if (SUCCEEDED(hr))
{
    // The conversion succeeded and propvar now is of the correct type for
    // PKEY_Keywords, or VT_EMPTY.
    PropVariantClear(&propvar);
}
else
{
    // The conversion failed and propvar is now VT_EMPTY.
}
```

## See also

[IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription)

[IShellItem2::GetPropertyStore](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitem2-getpropertystore)

[PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype)

[Property Description Schema](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-entry)

[typeInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-typeinfo)