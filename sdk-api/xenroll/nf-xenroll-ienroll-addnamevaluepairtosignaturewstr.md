# IEnroll::AddNameValuePairToSignatureWStr

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **AddNameValuePairToSignatureWStr** method adds the authenticated name-value pair of an [attribute](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) to the request. The [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) interprets the meaning of the name-value pair.
This method was first defined in the [IEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll2) interface.

## Parameters

### `Name` [in]

A null-terminated Unicode string that contains the name of the attribute, such as "2.5.4.6", for the country/region name.

### `Value` [in]

 A null-terminated Unicode string that contains the value of the attribute, such as "US" or "*DomainName*\*UserID*".

## Return value

The return value is an **HRESULT**, with S_OK returned if the call is successful.

## Remarks

The **AddNameValuePairToSignatureWStr** method is used to add attributes to the request.

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)

**IEnroll4**