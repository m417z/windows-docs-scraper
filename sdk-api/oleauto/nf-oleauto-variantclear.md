# VariantClear function

## Description

Clears a variant.

## Parameters

### `pvarg` [in, out]

The variant to clear.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **DISP_E_ARRAYISLOCKED** | The variant contains an array that is locked. |
| **DISP_E_BADVARTYPE** | The variant type is not a valid type of variant. |
| **E_INVALIDARG** | One of the arguments is not valid. |

## Remarks

Use this function to clear variables of type VARIANTARG (or VARIANT) before the memory containing the VARIANTARG is freed (as when a local variable goes out of scope).

The function clears a VARIANTARG by setting the vt field to VT_EMPTY. The current contents of the VARIANTARG are released first. If the vtfield is VT_BSTR, the string is freed. If the vtfield is VT_DISPATCH, the object is released. If the vt field has the VT_ARRAY bit set, the array is freed.

If the variant to be cleared is a COM object that is passed by reference, the vtfield of the pvargparameter is VT_DISPATCH | VT_BYREF or VT_UNKNOWN | VT_BYREF. In this case, **VariantClear** does not release the object. Because the variant being cleared is a pointer to a reference to an object, **VariantClear** has no way to determine if it is necessary to release the object. It is therefore the responsibility of the caller to release the object or not, as appropriate.

In certain cases, it may be preferable to clear a variant in code without calling **VariantClear**. For example, you can change the type of a VT_I4 variant to another type without calling this function. Safearrays of BSTR will have [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) called on each element not **VariantClear**. However, you must call **VariantClear** if a VT_type is received but cannot be handled. Safearrays of variant will also have **VariantClear** called on each member. Using **VariantClear** in these cases ensures that code will continue to work if Automation adds new variant types in the future.

Do not use **VariantClear** on uninitialized variants; use [VariantInit](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantinit) to initialize a new VARIANTARG or VARIANT.

Variants containing arrays with outstanding references cannot be cleared. Attempts to do so will return an HRESULT containing DISP_E_ARRAYISLOCKED.

#### Examples

The following example shows how to clear an array of variants, where `celt` is the number of elements in the array.

```cpp
for(int i = 0; i < celt; ++i)
   VariantClear(&rgvar[i]);
```

## See also

[Variant Manipulation Functions](https://learn.microsoft.com/previous-versions/windows/desktop/automat/variant-manipulation-functions)