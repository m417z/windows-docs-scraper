# IMDSPObject::Close

## Description

The **Close** method closes a file on a storage medium of a media device.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method must be implemented. It must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPObject Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspobject)

[IMDSPObject::Open](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject-open)

[IMDSPObject::Read](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject-read)

[IMDSPObject::Write](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject-write)