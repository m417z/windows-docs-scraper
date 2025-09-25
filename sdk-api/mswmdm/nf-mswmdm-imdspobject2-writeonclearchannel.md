# IMDSPObject2::WriteOnClearChannel

## Description

The **WriteOnClearChannel** method writes data to the object to the current position within the object, without using secure authenticated channels. This operation is valid only if the storage object represents a file. If **IMDSPObject2** is supported, this method must be implemented. Windows Media Device Manager does not fall back to [IMDSPObject::Write](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject-write) if this method fails.

## Parameters

### `pData` [in]

Pointer to the buffer containing the data to write to the object.

### `pdwSize` [in, out]

Pointer to a **DWORD** containing the number of bytes of data to write. Upon return, this parameter contains the actual number of bytes written.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method can be used with DRM-protected content. It is more efficient than [IMDSPObject::Write](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject-write) because this method does not involve encrypting and decrypting parameters.

Unlike **IMDSPObject::Write**, this method does not need to decrypt the data before writing to a device, and is therefore more efficient.

## See also

[Enabling Synchronization with Windows Media Player](https://learn.microsoft.com/windows/desktop/WMDM/enabling-synchronization-with-windows-media-player)

[IMDSPObject2 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspobject2)

[IMDSPObject2::ReadOnClearChannel](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject2-readonclearchannel)

[IMDSPObject::Write](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject-write)