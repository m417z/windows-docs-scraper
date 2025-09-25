# IWMDMObjectInfo::GetTotalLength

## Description

The **GetTotalLength** method retrieves the total play length of the object, in units appropriate to the format. The value returned is the total length regardless of the current settings of the play length and offset.

## Parameters

### `pdwLength` [out]

Pointer to a **DWORD** specifying the total length of the file, in units appropriate to the format.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

For playable files, the total length is specified in milliseconds.

For folders or file systems containing playable files, the value returned indicates the total number of playable files in a folder or in the root of a file system.

## See also

[IWMDMObjectInfo Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmobjectinfo)