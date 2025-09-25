# IMDSPObject::Read

## Description

The **Read** method reads data from the object at the current position. This operation is valid only if the storage object represents a file.

## Parameters

### `pData` [out]

Pointer to a buffer to receive the data read from the object. This parameter is included in the output message authentication code and must be encrypted using [CSecureChannelServer::EncryptParam](https://learn.microsoft.com/previous-versions/ms868509(v=msdn.10)). See Remarks.

### `pdwSize` [in, out]

Pointer to a **DWORD** specifying the number of bytes of data to read. Upon return, this parameter contains the actual amount of data read. This parameter must be included in the input message authentication code.

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

This method is optional. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[Encryption and Decryption](https://learn.microsoft.com/windows/desktop/WMDM/encryption-and-decryption)

[IMDSPObject Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspobject)

[IMDSPObject::Close](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject-close)

[IMDSPObject::Open](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject-open)

[IMDSPObject::Seek](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject-seek)

[IMDSPObject::Write](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject-write)