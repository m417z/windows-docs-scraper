# DRMGetBoundLicenseObject function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMGetBoundLicenseObject** function returns an object from a bound license.

## Parameters

### `hQueryRoot` [in]

A handle to a license or license object, from a previous call to this function or from [DRMCreateBoundLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateboundlicense).

### `wszSubObjectType` [in]

The type of XrML object to find. For more information, see Remarks.

### `iWhich` [in]

Zero-based index specifying which occurrence to retrieve.

### `phSubObject` [out]

A handle to the returned license object. Call [DRMCloseHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosehandle) to close the handle.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

There are many kinds of objects in a license, such as principals, rights, and access conditions. The Active Directory Rights Management system exposes an object-oriented interface to the underlying license XrML. This function, along with other **DRMGetBoundLicense_xxx** functions, allows an application to navigate this structure. For more information, see [Querying Licenses](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/querying-licenses). On first call, use the license handle itself as the query root.

On first call, this function takes the **DRMHANDLE** returned by [DRMCreateBoundLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateboundlicense).

The *wszSubObjectType* parameter identifies an XrML type as shown in the following example. Using g_wszQUERY_OBJECTTYPE to query the XrML would return "Group Identity Licensor."

```cpp
<PRINCIPAL internal-id="1">
  <OBJECT type="Group Identity Licensor">
  <ID type="Group Identity">someone@example.com</ID>
  <NAME>Pavel's Group Identity</NAME>
  </OBJECT>
```

Call [DRMCloseHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosehandle) to close the handle created by calling this function.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMGetBoundLicenseAttribute](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetboundlicenseattribute)

[DRMGetBoundLicenseAttributeCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetboundlicenseattributecount)

[DRMGetBoundLicenseObjectCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetboundlicenseobjectcount)

[Querying Licenses](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/querying-licenses)