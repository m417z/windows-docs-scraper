# IMFObjectReferenceStream::SaveReference

## Description

Stores the data needed to marshal an interface across a process boundary.

## Parameters

### `riid` [in]

Interface identifier of the interface to marshal.

### `pUnk` [in]

Pointer to the **IUnknown** interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFObjectReferenceStream](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfobjectreferencestream)