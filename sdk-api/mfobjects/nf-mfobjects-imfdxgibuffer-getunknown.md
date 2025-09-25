# IMFDXGIBuffer::GetUnknown

## Description

Gets an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer that was previously stored in the media buffer object.

## Parameters

### `guid` [in]

The identifier of the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer.

### `riid` [in]

The interface identifier (IID) of the interface being requested.

### `ppvObject` [out]

Receives a pointer to the interface. The caller must release the interface.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_NOINTERFACE** | The object does not support the specified interface. |
| **MF_E_NOT_FOUND** | The specified key was not found. |

## See also

[IMFDXGIBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfdxgibuffer)

[IMFDXGIBuffer::SetUnknown](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfdxgibuffer-setunknown)