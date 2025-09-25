# IMDSPObject::Write

## Description

The **Write** method writes data to the object at the current position within the object. This operation is valid only if the storage object represents a file.

## Parameters

### `pData` [in]

Pointer to the buffer containing the data to write to the object. This parameter is encrypted and must be decrypted using [CSecureChannelServer::DecryptParam](https://learn.microsoft.com/previous-versions/bb231598(v=vs.85)) with the MAC in *abMac*. See Remarks.

### `pdwSize` [in, out]

**DWORD** containing the number of bytes of data to write. Upon return, this parameter contains the actual number of bytes written. This parameter must be included in both the input and output message authentication codes.

### `abMac` [in, out]

Array of eight bytes containing the message authentication code for the parameter data of this method. (WMDM_MAC_LENGTH is defined as 8.)

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

The MAC used for encryption should include both *pData* and *pdwSize* in calls to [CSecureChannelServer::MACUpdate](https://learn.microsoft.com/previous-versions/ms868515(v=msdn.10)).

This method must be implemented. It must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[Encryption and Decryption](https://learn.microsoft.com/windows/desktop/WMDM/encryption-and-decryption)

[IMDSPObject Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspobject)

[IMDSPObject::Close](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject-close)

[IMDSPObject::Open](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject-open)

[IMDSPObject::Read](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject-read)