# VariantToBuffer function

## Description

Extracts the contents of a buffer stored in a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure of type VT_ARRRAY | VT_UI1.

## Parameters

### `varIn` [in]

Type: **REFVARIANT**

Reference to a source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

### `pv` [out]

Type: **VOID***

Pointer to a buffer of length *cb* bytes. When this function returns, contains the first *cb* bytes of the extracted buffer value.

### `cb` [in]

Type: **UINT**

The size of the *pv* buffer, in bytes. The buffer should be the same size as the data to be extracted, or smaller.

## Return value

Type: **HRESULT**

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | Data successfully extracted. |
| **E_INVALIDARG** | The [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) was not of type VT_ARRRAY \| VT_UI1. |
| **E_FAIL** | The [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) buffer value had fewer than *cb* bytes. |

## Remarks

This function is used when the calling application expects a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) to hold a buffer value. The calling application should check that the value has the expected length before it calls this function.

If the source [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) has type VT_ARRAY | VT_UI1, this function extracts the first *cb* bytes from the structure and places them in the buffer pointed to by *pv*.

If the stored value has fewer than *cb* bytes, then [VariantToBuffer](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttobuffer) fails and the buffer is not modified.

If the value has more than *cb* bytes, then [VariantToBuffer](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttobuffer) succeeds and truncates the value.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [VariantToBuffer](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttobuffer) to access a structure that has been stored in a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant).

```cpp
// VARIANT var;
// Assume variable var is initialized and valid.
// The application expects var to hold a WIN32_FIND_DATAW structure
// with sizeof(WIN32_FIND_DATAW) bytes.

HRESULT hr = E_UNEXPECTED;

// Verify that the value length is acceptable before you call VariantToBuffer.
if (VariantGetElementCount(var) == sizeof(WIN32_FIND_DATAW))
{
    WIN32_FIND_DATAW wfd;

    hr = VariantToBuffer(var, &wfd, sizeof(wfd));

    if (SUCCEEDED(hr))
    {
        // wfd is now initialized.
    }
}
```

## See also

[InitVariantFromBuffer](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfrombuffer)

[PropVariantToBuffer](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttobuffer)