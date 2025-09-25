# DRMGetUnboundLicenseAttribute function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMGetUnboundLicenseAttribute** function retrieves an unbound license attribute from the underlying XrML.

## Parameters

### `hQueryRoot` [in]

A handle to a license or object in the license, created by using [DRMGetUnboundLicenseObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetunboundlicenseobject) or [DRMParseUnboundLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmparseunboundlicense).

### `wszAttributeType` [in]

Name of the attribute to retrieve.

### `iWhich` [in]

Zero-based index of the attribute to retrieve.

### `peEncoding` [out]

An enumeration value specifying the encoding type of the return value.

### `pcBuffer` [in, out]

Size of the returned data, in characters, plus one for a null terminator.

### `pbBuffer` [out]

Attribute value.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Attributes hold information about an object, such as its name, issue time, or SKU value. All allocating and freeing of memory are the responsibility of the caller. To obtain the size of the returned value, first call this function with the attribute sought (such as "Issue Date"), and **NULL** in the *pbBuffer* value. The size required for the buffer will be passed out in *pcBuffer*.

An object may have several instances of an attribute with the same name. For example, a **RIGHT** object may have several name-value pairs. In this case, it may be necessary to iterate through all the instances of an attribute (g_wszQUERY_RIGHTSPARAMETERNAME or g_wszQUERY_RIGHTSPARAMETERVALUE in the preceding example) by first calling [DRMGetUnboundLicenseAttributeCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetunboundlicenseattributecount) to get a count of existing objects, and then looping through all *iWhich* instances of the attribute, starting at zero and incrementing by one.

This query will search only at the level immediately below the passed in object. So, for example, if the root license handle is passed in and the attribute to find is g_wszQUERY_SKUVALUE, the query will find nothing because the SKUVALUE appears at the second level or deeper (counting the license root as level 0).

The only attributes you can query for in an issuance license are g_wszQUERY_IDTYPE, g_wszQUERY_IDVALUE, g_wszQUERY_NAME, g_wszQUERY_ADDRESSTYPE, and g_wszQUERY_ADDRESSVALUE.

## See also

[DRMGetUnboundLicenseAttributeCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetunboundlicenseattributecount)

[DRMGetUnboundLicenseObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetunboundlicenseobject)

[DRMGetUnboundLicenseObjectCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetunboundlicenseobjectcount)

[Querying Licenses](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/querying-licenses)