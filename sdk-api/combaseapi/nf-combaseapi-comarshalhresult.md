# CoMarshalHresult function

## Description

Marshals an **HRESULT** to the specified stream, from which it can be unmarshaled using the [CoUnmarshalHresult](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-counmarshalhresult) function.

## Parameters

### `pstm` [in]

A pointer to the marshaling stream. See [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream).

### `hresult` [in]

The **HRESULT** in the originating process.

## Return value

This function can return the standard return values E_OUTOFMEMORY and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The **HRESULT** was marshaled successfully. |
| **STG_E_INVALIDPOINTER** | A bad pointer was specified for *pstm*. |
| **STG_E_MEDIUMFULL** | The medium is full. |

## Remarks

An **HRESULT** is process-specific, so an **HRESULT** that is valid in one process might not be valid in another. If you are writing your own implementation of [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal) and need to marshal an **HRESULT** from one process to another, either as a parameter or a return code, you must call this function. In other circumstances, you will have no need to call this function.

This function performs the following tasks:

1. Writes an **HRESULT** to a stream.
2. Returns an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) pointer to that stream.

## See also

[CoUnmarshalHresult](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-counmarshalhresult)

[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)