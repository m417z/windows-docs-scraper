# DownloadJavaEX function

Downloads the .cab file signature, verifies the permissions associated with the packages, and executes them based on authentication.

## Parameters

*Reserved* \[in\]

This parameter is reserved.

*pProviderData* \[in\]

A [**CRYPT\_PROVIDER\_DATA**](https://learn.microsoft.com/windows/win32/api/wintrust/ns-wintrust-crypt_provider_data) structure that contains certificate data such as file and zone permissions.

*pJava* \[in\]

A [**JAVA\_POLICY\_PROVIDER**](https://learn.microsoft.com/previous-versions//bb432350(v=vs.85)) structure that contains data related to the policy provider.

*pFunctions* \[in\]

A [**CRYPT\_PROVIDER\_FUNCTIONS**](https://learn.microsoft.com/windows/win32/api/wintrust/ns-wintrust-crypt_provider_functions) structure that contains a list of methods to verify certificate objects, signatures, and final policies.

*fCertificate* \[in\]

If a certificate is present, this parameter is **TRUE**. Otherwise, it is **FALSE**.

*pTrust* \[in\]

A [**JAVA\_TRUST**](https://learn.microsoft.com/windows/desktop/api/Capi/ns-capi-java_trust) structure that contains trust information such as encoded permission, encoder signature, and authentic return policy code.

## Return value

If the function succeeds, the return value is **S\_OK**. Otherwise, the return value is an error code.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|-----------------------------------------------------------------------------------------|
| DLL<br> | Javacypt.dll |

