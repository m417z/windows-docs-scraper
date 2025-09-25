# IMDSPStorage::GetRights

## Description

The **GetRights** method retrieves the rights information for an object.

## Parameters

### `ppRights` [out]

Pointer to an array of **WMDMRIGHTS** structures that contain the storage object rights information. This parameter is included in the output message authentication code.

### `pnRightsCount` [out]

Pointer to the number of **WMDMRIGHTS** structures in the *ppRights* array. This parameter is included in the output message authentication code.

### `abMac` [in, out]

Array of eight bytes containing the message authentication code for the parameter data of this method. (WMDM_MAC_LENGTH is defined as 8.)

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

Object rights describe the usage permissions for media content. For example, the **WMDMRIGHTS** structure can contain information concerning how many times a file can be played and who can play it.

The *ppRights* array is allocated by this method, and must be freed by the application using **CoTaskMemFree**, a standard Win32 function.

This method is optional. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorage)

[WMDMRIGHTS](https://learn.microsoft.com/windows/desktop/WMDM/wmdmrights)