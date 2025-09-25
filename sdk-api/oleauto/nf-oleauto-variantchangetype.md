## Description

> [!IMPORTANT]
> This API is affected by the problem described in Microsoft Support topic [VarI8FromCy produces incorrect value when CY value is very large](https://support.microsoft.com/help/2282810).

Converts a variant from one type to another.

## Parameters

### `pvargDest` [out]

The destination variant. If this is the same as *pvarSrc*, the variant will be converted in place.

### `pvarSrc` [in]

The variant to convert.

### `wFlags` [in]

Flags.

| Value | Meaning |
| --- | --- |
| **VARIANT_NOVALUEPROP** | Prevents the function from attempting to coerce an object to a fundamental type by getting the Value property. Applications should set this flag only if necessary, because it makes their behavior inconsistent with other applications. |
| **VARIANT_ALPHABOOL** | Converts a VT_BOOL value to a string containing either "True" or "False". |
| **VARIANT_NOUSEROVERRIDE** | For conversions to or from VT_BSTR, passes LOCALE_NOUSEROVERRIDE to the core coercion routines. |
| **VARIANT_LOCALBOOL** | For conversions from VT_BOOL to VT_BSTR and back, uses the language specified by the locale in use on the local computer. |

### `vt` [in]

The type to convert to. If the return code is S_OK, the **vt** field of the **pvargDest* is guaranteed to be equal to this value.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **DISP_E_BADVARTYPE** | The variant type is not a valid type of variant. |
| **DISP_E_OVERFLOW** | The data pointed to by *pvarSrc* does not fit in the destination type. |
| **DISP_E_TYPEMISMATCH** | The argument could not be coerced to the specified type. |
| **E_INVALIDARG** | One of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

The **VariantChangeType** function handles coercions between the fundamental types (including numeric-to-string and string-to-numeric coercions). The *pvarSrc* argument is changed during the conversion process. For example, if the source variant is of type VT_BOOL and the destination is of type VT_UINT, the *pvarSrc* argument is first converted to VT_I2 and then the conversion proceeds. A variant that has VT_BYREF set is coerced to a value by obtaining the referenced value. An object is coerced to a value by invoking the object's **Value** property (DISPID_VALUE).

Typically, the implementer of [IDispatch::Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke) determines which member is being accessed, and then calls **VariantChangeType** to get the value of one or more arguments. For example, if the [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) call specifies a **SetTitle** member that takes one string argument, the implementer would call **VariantChangeType** to attempt to coerce the argument to VT_BSTR. If **VariantChangeType** does not return an error, the argument could then be obtained directly from the **bstrVal** field of the VARIANTARG. If **VariantChangeType** returns DISP_E_TYPEMISMATCH, the implementer would set **puArgErr* to 0 (indicating the argument in error) and return DISP_E_TYPEMISMATCH from [Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke).

Arrays of one type cannot be converted to arrays of another type with this function.

**Note** The type of a VARIANTARG should not be changed in the *rgvarg* array in place.

## See also

[Variant Manipulation Functions](https://learn.microsoft.com/previous-versions/windows/desktop/automat/variant-manipulation-functions)

[VariantChangeTypeEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantchangetypeex)