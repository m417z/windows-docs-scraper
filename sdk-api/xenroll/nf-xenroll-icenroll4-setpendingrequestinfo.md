# ICEnroll4::setPendingRequestInfo

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **setPendingRequestInfo** method sets properties for a pending request. This method was first defined in the [ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4) interface.

## Parameters

### `lRequestID` [in]

An identifier for the request, as assigned by the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

### `strCADNS` [in]

The Domain Name System (DNS) name of the certification authority. The *strCADNS* parameter cannot be **NULL**.

### `strCAName` [in]

The name of the certification authority. The *strCAName* parameter cannot be **NULL**.

### `strFriendlyName` [in]

The display name of the certification authority. The *strFriendlyName* parameter can be **NULL**.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see
[Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).