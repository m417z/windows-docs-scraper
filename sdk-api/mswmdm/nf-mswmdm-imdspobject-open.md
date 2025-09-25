# IMDSPObject::Open

## Description

The **Open** method opens the associated object and prepares it for [Read](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject-read) or [Write](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject-write) operations. This operation is valid only if the storage object represents a file.

## Parameters

### `fuMode` [in]

Mode in which the file must be opened. It must be one of the following two values.

| Value | Description |
| --- | --- |
| MDSP_READ | Query whether a subsequent call to **Read** would be allowed. |
| MDSP_WRITE | Query whether a subsequent call to **Insert** would be allowed. |

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

If the underlying file-system does not support opening of multiple files at the same time, the service provider should gracefully the return Win32 error code ERROR_TOO_MANY_OPEN_FILES, if the client attempts to open more than one file at a time.

This method must be implemented. It must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPObject Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspobject)

[IMDSPObject::Close](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject-close)

[IMDSPObject::Read](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject-read)

[IMDSPObject::Seek](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject-seek)

[IMDSPObject::Write](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject-write)