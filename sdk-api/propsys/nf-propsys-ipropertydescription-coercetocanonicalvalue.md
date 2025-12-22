# IPropertyDescription::CoerceToCanonicalValue

## Description

Coerces the value to the canonical value, according to the property description.

## Parameters

### `ppropvar` [in, out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

On entry, contains a pointer to a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure that contains the original value. When this method returns, contains the canonical value.

## Return value

Type: **HRESULT**

If the failure code is not INPLACE_S_TRUNCATED or E_INVALIDARG, then coercion from the value's type to the property description's type was not possible, and the [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure has been cleared.

Possible results include the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. The property value specified by *ppropvar* is now in a canonical form. |
| **INPLACE_S_TRUNCATED** | The property value specified by *ppropvar* is now in a truncated, canonical form. |
| **E_INVALIDARG** | The *ppropvar* parameter is invalid. The [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure has been cleared. |

## Remarks

For more information, see the *type* attribute of the [typeInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-typeinfo) element in the property's .propdesc file.

Most property descriptions specify the type that their values are expected to use. For example, the property description for [System.Title](https://learn.microsoft.com/windows/desktop/properties/props-system-title) specifies that System.Title values should use `VT_LPWSTR`. This method coerces values to this type, and coerces the result into a canonical form.

It is important to note that if this method fails, it will have already called the [PropVariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/oe/oe-imimeallocator-propvariantclear) on the input [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure. Only if this method succeeds is the calling application responsible for calling the **PropVariantClear** on *ppropvar* when the structure is no longer needed.

The coercion performed by this method is also performed by the property system during [IPropertyStore::GetValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-getvalue) and [IPropertyStore::SetValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-setvalue) calls. Applications may depend on the property system to perform the coercions, or may use this method to perform the coercion at a time of the application's choosing.

The coercion is performed in four steps, as follows:

1. The following values are converted to `VT_EMPTY`.
   * Values of type `VT_NULL`.
   * Values of type `VT_LPWSTR, VT_BSTR`, or `VT_LPSTR` whose pointer is **NULL**.
   * Values of type `VT_LPWSTR, VT_BSTR`, or `VT_LPSTR` that are empty or consist entirely of spaces.
   * Values of type `VT_FILETIME` prior to midnight 1601/01/02.
2. If the value is not of type `VT_EMPTY` after Step 1, it is converted to the type specified by the property description. The type of a property description can be obtained using [IPropertyDescription::GetPropertyType](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertydescription-getpropertytype). See [typeInfo](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-typeinfo) for information about how the property schema influences the type of a property description. Conversions are performed as follows:
   * Values of type `VT_LPWSTR, VT_BSTR`, or `VT_LPSTR` are converted to `VT_VECTOR | VT_LPWSTR` using [InitPropVariantFromStringAsVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromstringasvector).
   * All other conversions are performed using [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype)
3. After Steps 2 and 3, the value is coerced into a canonical form based on its type. The canonical forms are summarized in the following table.

   | Value Type | Canonical Form |
   | --- | --- |
   | `VT_EMPTY` | Always canonical. |
   | `VT_LPWSTR` | * No leading or trailing spaces. The string is non-empty. The string is non-**NULL**. For example, `L"Alice"`.<br>* If this is a tree property (that is, if the typeInfo element's `isTreeProperty` attribute is **TRUE**), then it must not have leading or trailing forward slashes (/), must not have spaces between the text and the forward slashes, and must not have two consecutive forward slashes(/). For example, `L"Friend/Bob"`<br>* Coercion removes unnecessary characters and will result in `VT_EMPTY` if there was no content. |
   | `VT_VECTOR \| VT_LPWSTR` | * Each string in the vector must adhere to the rules for `VT_LPWSTR` listed above. In addition, the vector must have no duplicates and have no null pointers.<br>* If this is a tree property, then no value can be the ancestor of another value. For example, `L"Friend"` is an ancestor of L"Friend/Bob".<br>* If there is no content, coercion removes duplicate and ancestor characters and will result in `VT_EMPTY`. |
4. If applicable, the value is checked against the property description type enumeration. The following checks apply.

   | Enumeration Type | Value Type | Canonical Form |
   | --- | --- | --- |
   | Discrete or Ranged | `VT_EMPTY` | Always canonical |
   | Discrete | `VT_LPWSTR` | The string matches one of the enumerated strings allowed for the property. Comparisons are case-insensitive. If not, convert the value to `VT_EMPTY`. |
   | Discrete | Numeric | The number matches one of the enumerated values allowed for the property. If not, convert the value to `VT_EMPTY`. |
   | Discrete | `VT_VECTOR \| VT_LPWSTR` | Each string in the vector matches one of the enumerated strings allowed for the property. Comparisons are case-insensitive. If not, remove that string from the vector. If the resulting vector is empty, convert the value to `VT_EMPTY`. |
   | Discrete | `VT_VECTOR \|` Numeric | Each number in the vector matches one of the enumerated values allowed for the property. If not, remove that number from the vector. If the resulting vector is empty, convert the value to `VT_EMPTY`. |
   | Ranged | `VT_LPWSTR` | The string exists in the range allowed for the property. Comparisons are case-sensitive. If not, convert the value to `VT_EMPTY`. |
   | Ranged | Numeric | The number exists in the range allowed for the property. If not, convert the value to VT_EMPTY. |
   | Ranged | `VT_VECTOR \| VT_LPWSTR` | Each string in the vector exists in the range allowed for the property. Comparisons are case-sensitive. If not, remove that string from the vector. If the resulting vector is empty, convert the value to `VT_EMPTY`. |
   | Ranged | `VT_VECTOR` \| Numeric | Each number in the vector exists in the range allowed for the property. If not, remove that number from the vector. If the resulting vector is empty, convert the value to VT_EMPTY. |

## See also

[IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription)

[Property Description Schema](https://learn.microsoft.com/windows/desktop/properties/propdesc-schema-entry)