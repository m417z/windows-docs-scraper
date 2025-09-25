# IWMDMStorage4::GetRightsWithProgress

## Description

The **GetRightsWithProgress** method retrieves the rights information for the storage object, providing a callback mechanism for monitoring progress.

## Parameters

### `pIProgressCallback` [in]

Optional pointer to an [IWMDMProgress3](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress3) interface to be used by Windows Media Device Manager to report progress back to the application.

### `ppRights` [out]

Pointer to an array of [WMDMRIGHTS](https://learn.microsoft.com/windows/desktop/WMDM/wmdmrights) structures that contain the storage object rights information. Memory for this array is allocated by Windows Media Device Manager. When the calling application has finished accessing this array, the memory must be freed by using **CoTaskMemFree**.

### `pnRightsCount` [out]

Pointer to the number of **WMDMRIGHTS** structures in the *ppRights* array.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

Object rights describe the usage permissions for digital media content. For example, the **WMDMRIGHTS** structure can contain information concerning how many times a file can be played and who can play it.

Retrieving rights from a licensed file can sometimes be a lengthy request; this function allows a rights request to be performed asynchronously.

The secure content provider can generate event notifications on the callback *pIProgressCallback* in addition to the progress notifications. Examples of such events include acquiring a secure clock, initializing DRM, and so on. These events are described in [IWMDMProgress3::Progress3](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmprogress3-progress3).

This method is identical to [IWMDMStorage::GetRights](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage-getrights), except it returns progress, and does not provide a MAC for parameter verification.

## See also

[IWMDMStorage4 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage4)