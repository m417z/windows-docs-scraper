# IWMDMRevoked::GetRevocationURL

## Description

The **GetRevocationURL** method retrieves the URL from which updated components can be downloaded.

## Parameters

### `ppwszRevocationURL` [in, out]

Pointer to a string containing a revocation URL. This buffer is created and freed by the caller.

### `pdwBufferLen` [in, out]

Size of the buffer holding the revocation URL.

### `pdwRevokedBitFlag` [out]

Pointer to a **DWORD** specifying information on what component(s) have been revoked. This should be one or more of the following values, combined using a bitwise **OR**.

| Flag | Description |
| --- | --- |
| WMDM_WMDM_REVOKED | Windows Media Device Manager itself has been revoked. |
| WMDM_APP_REVOKED | The application has been revoked and needs to be updated before any DRM-protected content can be transferred. |
| WMDM_SP_REVOKED | The service provider has been revoked and needs to be updated before any DRM-protected content can be transferred to it. |
| WMDM_SCP_REVOKED | The secured content provider has been revoked and needs to be updated before any DRM-protected content can be transferred. |

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method retrieves the URL from which updated components can be downloaded. If this method is not implemented by the revoked component, a default Microsoft URL is used. This location is maintained by Microsoft and contains any updates to components revoked by the Microsoft digital rights management system.

## See also

[IWMDMRevoked Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmrevoked)