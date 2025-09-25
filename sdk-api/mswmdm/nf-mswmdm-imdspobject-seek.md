# IMDSPObject::Seek

## Description

The **Seek** method sets the current position within the object. This operation is valid only if the storage object represents a file.

## Parameters

### `fuFlags` [in]

Mode in which the file must be opened. It must be one of the values in the following table.

| Value | Description |
| --- | --- |
| MDSP_SEEK_BOF | Seek *dwOffset* bytes forward from the beginning of the file. |
| MDSP_SEEK_CUR | Seek *dwOffset* bytes forward from the current position. |
| MDSP_SEEK_EOF | Seek *dwOffset* bytes backward from the end of the file. |

### `dwOffset` [in]

**DWORD** containing the number of bytes to seek.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method is optional. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPObject Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspobject)

[IMDSPObject::Open](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject-open)

[IMDSPObject::Read](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspobject-read)