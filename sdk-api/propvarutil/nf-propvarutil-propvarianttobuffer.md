# PropVariantToBuffer function

## Description

Extracts the buffer value from a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure of type VT_VECTOR | VT_UI1 or VT_ARRRAY | VT_UI1.

## Parameters

### `propvar` [in]

Type: **REFPROPVARIANT**

The source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `pv` [out]

Type: **VOID***

Pointer to a buffer of length *cb* bytes. When this function returns, contains the first *cb* bytes of the extracted buffer value.

### `cb` [in]

Type: **UINT**

The buffer length, in bytes.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | If successful, or an error value otherwise. |
| **E_INVALIDARG** | The[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) was of the wrong type. |
| **E_FAIL** | The[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) value had fewer than *cb* bytes. |

## Remarks

This function is used in places where the calling application expects a[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold a buffer value. The calling application should check that the value has the expected length before calling this function.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type VT_VECTOR | VT_UI1 or VT_ARRAY | VT_UI1, this function extracts the first *cb* bytes from the value and places them in the buffer pointed to by *pv*. If the value has fewer than *cb* bytes, then [PropVariantToBuffer](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttobuffer) fails and the buffer is not modified. If the value has more than *cb* bytes, then **PropVariantToBuffer** succeeds and truncates the value.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use PropVariantToBuffer to access a structure that has been stored in a PROPVARIANT".

```cpp
// IPropertyStore *ppropstore;
// Assume variable ppropstore is initialized and valid
PROPVARIANT propvar = {0};
HRESULT hr = ppropstore->GetValue(PKEY_FindData, &propvar);

if (SUCCEEDED(hr))
{
    // PKEY_FindData is expected to produce a VT_VECTOR | VT_UI1 with sizeof(WIN32_FIND_DATAW) bytes
    // We need to verify that the value length is acceptable before calling PropVariantToBuffer
    hr = E_UNEXPECTED;

    if (PropVariantGetElementCount(propvar) == sizeof(WIN32_FIND_DATAW))
    {
        WIN32_FIND_DATAW wfd;
        hr = PropVariantToBuffer(propvar, &wfd, sizeof(wfd));

        if (SUCCEEDED(hr))
        {
            // wfd is now initialized
        }
    }
    PropVariantClear(&propvar);
}
```

## See also

[InitPropVariantFromBuffer](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfrombuffer)

[VariantToBuffer](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttobuffer)