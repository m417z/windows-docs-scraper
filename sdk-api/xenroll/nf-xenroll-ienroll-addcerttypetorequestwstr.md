# IEnroll::AddCertTypeToRequestWStr

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **AddCertTypeToRequestWStr** method adds a certificate template to a request (used to support the enterprise [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA)). This method was first defined by the [IEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll2) interface.

The **AddCertTypeToRequestWStr** method is an advanced topic that is associated with the Microsoft Certificate Services enterprise Policy Module. Its use is not recommended for most applications.

The phrase "certificate type" is synonymous with "certificate template."

## Parameters

### `szw` [in]

Fully qualified name of the certificate template which is being added to the [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). This value is interpreted by the certification authority.

## Return value

The return value is an **HRESULT**, with S_OK returned if the call is successful.

## Remarks

This method can be called multiple times if more than one certificate template is desired for the request.

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)