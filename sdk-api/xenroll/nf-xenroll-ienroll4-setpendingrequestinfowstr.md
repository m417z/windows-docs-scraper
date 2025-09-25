# IEnroll4::setPendingRequestInfoWStr

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **setPendingRequestInfoWStr** method sets properties for a pending request. This method was first defined in the [IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4) interface.

## Parameters

### `lRequestID` [in]

Identifier for the request, as assigned by the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA).

### `pwszCADNS` [in]

A pointer to a null-terminated wide character string that represents the CA's Domain Name System (DNS) name. This parameter cannot be null.

### `pwszCAName` [in]

A pointer to a null-terminated wide character string that represents the CA's name. This parameter cannot be null.

### `pwszFriendlyName` [in]

A pointer to a null-terminated wide character string that represents the CA's display name. This parameter may be null.

## See also

[IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)