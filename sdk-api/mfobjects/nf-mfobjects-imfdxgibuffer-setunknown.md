# IMFDXGIBuffer::SetUnknown

## Description

Stores an arbitrary [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer in the media buffer object.

## Parameters

### `guid` [in]

The identifier for the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer. This identifier is used as a key to retrieve the value. It can be any **GUID** value.

### `pUnkData` [in]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface. Set this parameter to **NULL** to clear a pointer that was previously set.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **ERROR_OBJECT_ALREADY_EXISTS** | An item already exists with this key. |

## Remarks

To retrieve the pointer from the object, call [IMFDXGIBuffer::GetUnknown](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfdxgibuffer-getunknown).

## See also

[IMFDXGIBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfdxgibuffer)

[IMFDXGIBuffer::GetUnknown](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfdxgibuffer-getunknown)