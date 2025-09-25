# IMDSPRevoked::GetRevocationURL

## Description

The **GetRevocationURL** method retrieves the URL from which updated components can be downloaded.

## Parameters

### `ppwszRevocationURL` [in, out]

Pointer to a Unicode string where the revocation URL should be written.

### `pdwBufferLen` [in, out]

Number of **WCHAR** characters that the buffer supplied by the client can hold; on return it contains the required number of characters.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

The **IMDSPRevoked** interface retrieves the URL from which updated components can be downloaded if the service provider is ever revoked by any digital rights management system. If this method is not implemented, a default Microsoft URL will be used. This location is maintained by Microsoft and contains updates to components revoked by the Microsoft digital rights management system.

## See also

[IMDSPRevoked Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdsprevoked)