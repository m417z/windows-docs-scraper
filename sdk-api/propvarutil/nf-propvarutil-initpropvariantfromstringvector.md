# InitPropVariantFromStringVector function

## Description

Initializes a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure from a specified string vector.

## Parameters

### `prgsz` [in]

Type: **PCWSTR***

Pointer to a buffer that contains the source string vector.

### `cElems` [in]

Type: **ULONG**

The number of vector elements in *prgsz*.

### `ppropvar` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

When this function returns, contains the initialized [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[InitPropVariantFromString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromstring)

[InitPropVariantFromStringAsVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromstringasvector)

[InitVariantFromString](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initvariantfromstring)

[PropVariantToStringVector](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttostringvector)