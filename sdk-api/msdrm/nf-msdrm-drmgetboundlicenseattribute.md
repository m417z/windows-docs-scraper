# DRMGetBoundLicenseAttribute function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMGetBoundLicenseAttribute** function retrieves a bound license attribute from the license XrML.

## Parameters

### `hQueryRoot` [in]

A handle to a root query object, from a previous call to this function or from [DRMCreateBoundLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateboundlicense).

### `wszAttribute` [in]

The attribute to retrieve.

### `iWhich` [in]

Zero-based index of the occurrence to retrieve.

### `peEncoding` [out]

Encoding type used.

### `pcBuffer` [in, out]

Size, in characters, of the attribute retrieved plus one for a terminating null character.

### `pbBuffer` [out]

Pointer to the attribute object.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The Active Directory Rights Management system exposes an object-oriented interface to the underlying license XrML. This function, along with other **DRMGetBoundLicense_xxx** functions, allows an application to navigate this structure.

Attributes hold information about an object, such as its name, issue time, or SKU value. To obtain attribute information, you must first determine the size of the buffer needed to hold the retrieved information by calling the function with **NULL** in the *pbBuffer* value. If the function succeeds and returns a value in *pcBuffer*, then allocate a properly sized buffer by using this value and call the function again, passing in to *pbBuffer* the allocated buffer to receive the value of the attribute.

An object can have several instances of an attribute with the same name. For example, there can be several authenticator type values in a license. In this case, it may be necessary to iterate through all the instances of an attribute by first calling [DRMGetBoundLicenseAttributeCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetboundlicenseattributecount) to get a count of existing objects and then looping through all *iWhich* instances of the attribute, starting at zero and incrementing by one.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMGetBoundLicenseAttributeCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetboundlicenseattributecount)

[DRMGetBoundLicenseObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetboundlicenseobject)

[DRMGetBoundLicenseObjectCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetboundlicenseobjectcount)