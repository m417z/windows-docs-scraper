# IMDSPObject::Rename

## Description

The **Rename** method renames the associated object which can be a file or a folder.

## Parameters

### `pwszNewName` [in]

Pointer to a wide-character null-terminated string to receive a new name for the object. For information on how to use the **LPWSTR** variable type, see the Windows documentation.

### `pProgress` [in]

Pointer to an application-implemented [IWMDMProgress](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress) interface that enables the application to receive progress notification for lengthy renaming operations.

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

[IWMDMProgress Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress)