# DRMSetApplicationSpecificData function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMSetApplicationSpecificData** function allows an issuance license to store arbitrary name-value pairs for use by the content-consuming application.

## Parameters

### `hIssuanceLicense` [in]

A handle to an issuance license.

### `fDelete` [in]

A flag that indicates whether to add or delete this name-value pair. **FALSE** indicates add; **TRUE** indicates delete.

### `wszName` [in]

The name of the data.

### `wszValue` [in]

The value of the data.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The values stored can be used to pass information to a consuming application, such as the version and name of the publishing application, contact information, or any other arbitrary information. Information is stored in a zero-based array and is retrieved by using the [DRMGetApplicationSpecificData](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetapplicationspecificdata) function. This function is used both to store a value or delete a stored value, depending on the flag passed in.

One data pair that is processed by an Active Directory Rights Management Services (AD RMS) server is the string pair "Allow_Server_Editing"/"True". When an issuance license has this value pair, it will allow the service, or any trusted service, to reuse the content key. This allows an issuance license to be republished by using the AD RMS SOAP function [EditIssuanceLicense](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/-editissuancelicense). This function takes in an old issuance license (with this name-value pair) and a new unsigned issuance license, and puts the content key into the new license. The pair "Allow_Server_Editing"/"True" must be added to the new issuance license if you want to allow publishing again.

To prevent republishing, remove this name-value pair or do not include it (do not add the data item with the value "False").

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMGetApplicationSpecificData](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetapplicationspecificdata)