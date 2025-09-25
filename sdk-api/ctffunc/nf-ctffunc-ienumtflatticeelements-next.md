# IEnumTfLatticeElements::Next

## Description

Obtains the specified number of elements in the enumeration sequence from the current position.

## Parameters

### `ulCount` [in]

Specifies the number of elements to obtain.

### `rgsElements` [out]

Pointer to an array of [TF_LMLATTELEMENT](https://learn.microsoft.com/windows/desktop/api/ctffunc/ns-ctffunc-tf_lmlattelement) structures that receives the requested data. This array must be at least *ulCount* elements in size.

The caller must free the **bstrText** member of every structure obtained using [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) when it is no longer required.

### `pcFetched` [out]

Pointer to a ULONG value that receives the number of elements actually obtained. This value can be less than the number of items requested. This parameter can be **NULL**.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method reached the end of the enumeration before the specified number of elements could be obtained. |
| **E_INVALIDARG** | *rgsElements* is invalid. |

## See also

[IEnumTfLatticeElements](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-ienumtflatticeelements)

[TF_LMLATTELEMENT](https://learn.microsoft.com/windows/desktop/api/ctffunc/ns-ctffunc-tf_lmlattelement)