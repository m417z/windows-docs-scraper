# CoUnmarshalHresult function

## Description

Unmarshals an **HRESULT** type from the specified stream.

## Parameters

### `pstm` [in]

A pointer to the stream from which the **HRESULT** is to be unmarshaled.

### `phresult` [out]

A pointer to the unmarshaled **HRESULT**.

## Return value

This function can return the standard return values E_OUTOFMEMORY and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The **HRESULT** was unmarshaled successfully. |
| **STG_E_INVALIDPOINTER** | *pStm* is an invalid pointer. |

## Remarks

You do not explicitly call this function unless you are performing custom marshaling (that is, writing your own implementation of [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal)), and your implementation needs to unmarshal an **HRESULT**.

You must use **CoUnmarshalHresult** to unmarshal **HRESULT** values previously marshaled by a call to the [CoMarshalHresult](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-comarshalhresult) function.

This function performs the following tasks:

1. an **HRESULT** from a stream.
2. Returns the **HRESULT**.

## See also

[CoMarshalHresult](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-comarshalhresult)

[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)