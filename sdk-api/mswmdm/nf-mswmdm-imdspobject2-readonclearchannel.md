# IMDSPObject2::ReadOnClearChannel

## Description

The **ReadOnClearChannel** method reads data from the object at the current position without using secure authenticated channels. This is still secure for use with DRM-protected content. This operation is valid only if the storage object represents a file. If **IMDSPObject2** is supported, this method must be implemented. Windows Media Device Manager does not fall back to [IMDSPObject::Read](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject-read) if this method fails.

## Parameters

### `pData` [out]

Pointer to a buffer to receive the data read from the object.

### `pdwSize` [in, out]

Pointer to a **DWORD** specifying the number of bytes of data to read. Upon return, this parameter contains the actual amount of data read.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method can be used for DRM-protected content. This method is more efficient than [IMDSPObject::Read](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject-read) because this method does not involve encrypting and decrypting parameters.

## See also

[Enabling Synchronization with Windows Media Player](https://learn.microsoft.com/windows/desktop/WMDM/enabling-synchronization-with-windows-media-player)

[IMDSPObject2 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspobject2)

[IMDSPObject2::WriteOnClearChannel](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject2-writeonclearchannel)

[IMDSPObject::Read](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject-read)