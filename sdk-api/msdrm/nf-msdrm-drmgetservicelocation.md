# DRMGetServiceLocation function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMGetServiceLocation** function retrieves the URL of a server that can perform various rights management services, such as activation or license acquisition.

## Parameters

### `hClient` [in, optional]

A handle to a client session. The handle can be obtained by using the [DRMCreateClientSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateclientsession) function. The handle is optional and can be **NULL**.

### `uServiceType` [in]

Specifies the type of service desired. This can be one of the following values.

#### DRM_SERVICE_TYPE_ACTIVATION

Retrieve the computer activation service.

#### DRM_SERVICE_TYPE_CERTIFICATION

Retrieve the [rights account certificate](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/r-gly) service.

#### DRM_SERVICE_TYPE_CLIENTLICENSOR

Retrieve the [client licensor certificates](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/c-gly) service (for offline publishing).

#### DRM_SERVICE_TYPE_PUBLISHING

Retrieve the [issuance license](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/i-gly) signing service (for online publishing).

#### DRM_SERVICE_TYPE_SILENT

Suppresses the appearance of any user-interface dialog boxes when the request is made to retrieve the service location.

### `uServiceLocation` [in]

Specifies where to find the AD RMS server. This can be one of the following values.

#### DRM_SERVICE_LOCATION_ENTERPRISE

Look within the enterprise for an AD RMS server.

#### DRM_SERVICE_LOCATION_INTERNET

Look on the Internet for an AD RMS server.

### `wszIssuanceLicense` [in]

A pointer to a null-terminated Unicode string that contains a signed issuance license. This parameter can be **NULL**. For more information, see Remarks.

### `puServiceURLLength` [in, out]

A pointer to a **UINT** that, on input, contains the size, in characters, of the *wszServiceURL* buffer. This value includes the terminating null character.

After the function returns, this **UINT** contains the number of characters, including the terminating null character, that were copied to the *wszServiceURL* buffer.

If *wszServiceURL* is **NULL**, this **UINT** receives the number of characters, including the terminating null character, that are required for the server URL.

### `wszServiceURL` [out]

A pointer to a Unicode string buffer that receives the URL of the server. The *puServiceURLLength* parameter contains the size, in characters, including the terminating null character, of this buffer.

If this parameter is **NULL**, *puServiceURLLength* receives the number of characters, including the terminating null character, that are required for the server URL.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Discovery of the service URL depends on the interaction between the *uServiceType*, *uServiceLocation*, and *wszIssuanceLicense* parameters in the following manner.

If you set the *uServiceType* parameter to DRM_SERVICE_TYPE_CERTIFICATION or to DRM_SERVICE_TYPE_ACTIVATION and:

* You pass a signed issuance license to the *wszIssuanceLicense* parameter. The licensing URL is retrieved from the signed issuance license, a call is made to the licensing server to discover the certification URL that corresponds with the calling user, and the function returns the certification URL.
* You set the *wszIssuanceLicense* parameter to **NULL** and the *uServiceLocation* parameter to DRM_SERVICE_LOCATION_INTERNET, the function returns an error code of E_DRM_USE_DEFAULT.
* You set the *wszIssuanceLicense* parameter to **NULL**, and the *uServiceLocation* parameter to DRM_SERVICE_LOCATION_ENTERPRISE, the URL is retrieved from the registry or from Active Directory (AD).

If you set the *uServiceType* parameter to DRM_SERVICE_TYPE_PUBLISHING or to DRM_SERVICE_TYPE_CLIENTLICENSOR and:

* You set the *uServiceLocation* parameter to DRM_SERVICE_LOCATION_INTERNET, the Passport service is supported to retrieve a service URL from the web.
* You set the *uServiceLocation* parameter to DRM_SERVICE_LOCATION_ENTERPRISE and the *wszIssuanceLicense* parameter to **NULL**, the licensing service URL is retrieved from the registry and returned by the function call. Or, in the absence of a registry entry, the certification URL is retrieved from the service connection point in Active Directory (AD), a call is made to the certification server to discover the licensing service URL, and the function returns the licensing service URL.
* You set the *uServiceLocation* parameter to DRM_SERVICE_LOCATION_ENTERPRISE and pass a signed issuance license to the *wszIssuanceLicense* parameter, the function attempts to retrieve the configured licensing URL from the registry. If this attempt fails, the licensing URL is retrieved from the signed issuance license and a call is made to the licensing server to discover the user's specific licensing URL.

For the preceding cases where the function searches the registry, you can force your application to find a specific URL by adding the appropriate registry key in the following list, along with the URL, as a string value called **(default)**. Do not add the .asmx page to the URL.

| Registry key | Description |
| --- | --- |
| * 32-bit application on a 32-bit computer<br>* 64-bit application on a 64-bit computer<br><br>**HKEY_LOCAL_MACHINE**\**SOFTWARE**\**Microsoft**\**MSDRM**\**ServiceLocation**\**Activation**<br><br>* 32-bit application on a 64-bit computer<br><br>**HKEY_LOCAL_MACHINE**\**SOFTWARE**\**Wow6432Node**\**Microsoft**\**MSDRM**\**ServiceLocation**\**Activation** | For RMS v1.0, set this registry value to the URL of a computer activation service. To use this value for certification, set it to the certification virtual root of the enterprise.<br><br>Beginning with RMS v1.0 SP1, this value can only be used to discover a certification service. Therefore, set it to the URL of the rights account virtual root, http://*ServerName*/_wmcs/certification. |
| * 32-bit application on a 32-bit computer<br>* 64-bit application on a 64-bit computer<br><br>**HKEY_LOCAL_MACHINE**\**SOFTWARE**\**Microsoft**\**MSDRM**\**ServiceLocation**\**EnterprisePublishing**<br><br>* 32-bit application on a 64-bit computer<br><br>**HKEY_LOCAL_MACHINE**\**SOFTWARE**\**Wow6432Node**\**Microsoft**\**MSDRM**\**ServiceLocation**\**EnterprisePublishing** | Set this registry value to the URL of a service that signs issuance licenses within an enterprise network. |
| * 32-bit application on a 32-bit computer<br>* 64-bit application on a 64-bit computer<br><br>**HKEY_LOCAL_MACHINE**\**SOFTWARE**\**Microsoft**\**MSDRM**\**ServiceLocation**\**CloudPublishing**<br><br>* 32-bit application on a 64-bit computer<br><br>**HKEY_LOCAL_MACHINE**\**SOFTWARE**\**Wow6432Node**\**Microsoft**\**MSDRM**\**ServiceLocation**\**CloudPublishing** | Set this registry value to the URL of a service that signs issuance licenses over the Internet. |

The application is responsible for allocating and freeing memory for the retrieved data. To find the buffer size required, call the function with **NULL** in the *wszServiceURL* parameter. The buffer size will be passed back to you through the *puServiceURLLength* parameter.

For a service discovery code example, see [OnlineSigning_GetServiceURL.cpp](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/onlinesigning-getserviceurl-cpp). There is no service discovery for acquiring [end-user licenses](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/e-gly) because this information can be stored in the [issuance license](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/i-gly) used to acquire the *end-user license*.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMActivate](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmactivate)

[OnlineSigning_GetServiceURL.cpp](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/onlinesigning-getserviceurl-cpp)