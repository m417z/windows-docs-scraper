# IMFObjectReferenceStream::LoadReference

## Description

Marshals an interface from data stored in the stream.

## Parameters

### `riid` [in]

Interface identifier of the interface to marshal.

### `ppv` [out]

Receives a pointer to the requested interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFObjectReferenceStream](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfobjectreferencestream)