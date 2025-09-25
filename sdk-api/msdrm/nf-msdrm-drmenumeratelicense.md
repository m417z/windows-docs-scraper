# DRMEnumerateLicense function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMEnumerateLicense** function enumerates valid licenses, [machine certificates](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/m-gly) or [rights account certificates](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/r-gly), [revocation lists](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/r-gly) for the current user, or issuance license templates.

## Parameters

### `hSession` [in]

A handle to a client or license storage session. The type of session passed into *hSession* depends on the type of item to enumerate. To enumerate [end-user licenses](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/e-gly), use a license storage session created by using the [DRMCreateLicenseStorageSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreatelicensestoragesession) function. To enumerate [machine certificates](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/m-gly), [rights account certificates](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/r-gly), [client licensor certificates](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/c-gly), or issuance license templates, use a client session created by using the [DRMCreateClientSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateclientsession) function. Use either type of handle to enumerate [revocation lists](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/r-gly).

### `uFlags` [in]

Contains one or more of the following values that specifies which types of items to enumerate and other options.

The following flag can be combined with other flags to specify additional enumeration options.

#### DRM_EL_EXPIRED

Use this value with flags used to enumerate identifiers, such as **DRM_EL_GROUPIDENTITY_LID**, to enumerate expired items of the specified type. This simplifies deleting expired items from the license store, keeping the store small and improving performance.

The following flags are used to enumerate [end-user licenses](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/e-gly).

#### DRM_EL_EUL

Enumerate [end-user licenses](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/e-gly) for the current license storage session.

#### DRM_EL_EUL_LID

Enumerate [end-user license](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/e-gly) identifiers for the current license storage session. The identifier of each *end-user license* is returned in the *wszCertificateData* parameter.

The following flags are used to enumerate [client licensor certificates](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/c-gly). These flags allow an application to enumerate through licensors in licenses available to the current user.

#### DRM_EL_CLIENTLICENSOR

Enumerate all [client licensor certificates](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/c-gly) in the certificate store.

#### DRM_EL_CLIENTLICENSOR_LID

Enumerate [client licensor certificates](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/c-gly) identifiers for the client session passed in. The client licensor certificate identifier is returned in the *wszCertificateData* parameter.

#### DRM_EL_SPECIFIED_CLIENTLICENSOR

Return the [client licensor certificate](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/c-gly) that corresponds to the email address in the client session.

The following flag is used to enumerate [machine certificates](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/m-gly).

#### DRM_EL_MACHINE

Enumerate the selected [machine certificate](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/m-gly).

Each user has two machine certificates. The valid index value for machine certificates is zero or one.

**Note** Due to updates to enable cryptographic mode-2, DRMActivate(machine) will write two machine certificates to the store. Unless an application makes direct calls to the certification web method on the RMS server, the calling application does not need to distinguish between the two machine certificates; the machine certificate that corresponds to the server cryptographic mode will be used.

For more information, see [RSA key length is increased to 2048 bits for AD RMS in Windows 7 or in Windows Server 2008 R2](https://support.microsoft.com/help/2627273).

If *hSession* was created by a call to [DRMCreateClientSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateclientsession), the returned certificate is from the per-user certificate store and the value pointed to by *pfSharedFlag* is set to **FALSE**. If *hSession* was created by a call to [DRMCreateLicenseStorageSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreatelicensestoragesession), the value pointed to by *pfSharedFlag* is its original value.

**Windows Server 2008 R2, Windows 7, Windows Server 2008 with SP2, Windows Vista with SP2 or Rights Management Services 1.0:** For Rights Management Services 1.0, the retrieved certificate is from the machine store and the value pointed to by *pfSharedFlag* is set to **TRUE**; *uIndex* must be set to zero.

The machine must be activated before specifying this flag. If the machine is not activated, the function will return **E_DRM_NEEDS_MACHINE_ACTIVATION**.

The following flags are used to enumerate [rights account certificates](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/r-gly).

#### DRM_EL_GROUPIDENTITY

Enumerate the [rights account certificates](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/r-gly) for the currently logged-in user. This includes both shared and restricted users.

#### DRM_EL_GROUPIDENTITY_LID

Enumerate the [rights account certificates](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/r-gly) identifiers for the currently logged-in user. This includes both shared and restricted users. The *rights account certificates* identifier will be returned in the *wszCertificateData* parameter.

#### DRM_EL_GROUPIDENTITY_NAME

Enumerate the rights account names for the current user.

#### DRM_EL_SPECIFIED_GROUPIDENTITY

Return the [rights account certificates](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/r-gly) for the specified user when the client session was created by using the [DRMCreateClientSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateclientsession) function.

The following flags are used to enumerate [revocation lists](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/r-gly).

All certificates can include [revocation lists](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/r-gly), so you can pass in either a client or license storage session to this function. A client session handle passed in will retrieve *revocation lists* for [rights account certificates](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/r-gly) or [client licensor certificates](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/c-gly). A license storage session handle passed in will retrieve *revocation lists* for [end-user licenses](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/e-gly).

#### DRM_EL_REVOCATIONLIST

Enumerate [revocation lists](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/r-gly).

#### DRM_EL_REVOCATIONLIST_LID

Enumerate [revocation list](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/r-gly) identifiers. The revocation list identifier will be returned in the *wszCertificateData* parameter.

The following flag can be used to retrieve the display name of the issuer.

#### DRM_EL_ISSUERNAME

This flag cannot be used with the **DRM_EL_EXPIRED** flag, and it must be used with one of the following flags:

* **DRM_EL_CLIENTLICENSOR**
* **DRM_EL_GROUPIDENTITY**
* **DRM_EL_SPECIFIED_CLIENTLICENSOR**
* **DRM_EL_SPECIFIED_GROUPIDENTITY**

The following flags can be used to enumerate templates.

#### DRM_EL_ISSUANCELICENSE_TEMPLATE

Enumerate issuance license templates. This flag is available beginning with Windows Vista with SP1 and Windows Server 2008.

#### DRM_EL_ISSUANCELICENSE_TEMPLATE_LID

Enumerate issuance license template identifiers (GUIDs). This flag is available beginning with Windows Vista with SP1 and Windows Server 2008.

### `uIndex` [in]

The index number of the certificate or license to retrieve. To begin an enumeration, pass in zero for this parameter. To obtain subsequent licenses, increment this value until the function returns **E_DRM_NO_MORE_DATA**. For more information, see Remarks.

### `pfSharedFlag` [in, out]

A pointer to a **BOOL** value that receives one (1) if the retrieved license is shared or zero (0) if the retrieved license is not shared.

### `puCertificateDataLen` [in, out]

A pointer to a UINT value that, on entry, contains the size of the *wszCertificateData* buffer. This size includes the terminating null character. After the function returns, this value contains the number of characters copied to the buffer, including the terminating null character.

To obtain the necessary size of the buffer, pass **NULL** for *wszCertificateData*. The required number of characters, including the terminating null character, will be placed in this value.

### `wszCertificateData` [out]

A pointer to a null-terminated Unicode string that receives the license, ID, or template depending on which flags were
set.

To obtain the necessary size of this buffer, pass **NULL** for *wszCertificateData*. The required number of characters, including the terminating null character, will be placed in *puCertificateDataLen*.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

By default, this function enumerates only unexpired licenses as determined by comparing the **VALIDITYTIME** element in each license with the creation time of the session object. To include expired licenses in the enumeration, combine the *uFlags* parameter with **DRM_EL_EXPIRED**.

Also, if the **ID** element in the **ISSUEDPRINCIPALS** element of the license does not match the user ID associated with the session object, or the session user ID does not match the ID of the logged–on user, this function will fail. For more information, see [DRMCreateClientSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateclientsession).

The following sections discuss how to enumerate the various types of licenses. When iterating through a collection, you can examine each license retrieved by manually parsing the XrML string or, in some cases, by binding to the license and using the **DRMGetBoundLicense*** functions.

Perform the following steps to enumerate an end-user license:

1. Call [DRMCreateLicenseStorageSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreatelicensestoragesession), passing in a signed issuance license.
2. Set the *uIndex* parameter to zero and the *uFlags* parameter to **DRM_EL_EUL** and call **DRMEnumerateLicense**. The AD RMS client retrieves the first valid EUL for which the content ID matches the content ID of the issuance license used to create the license storage session. If, however, the issuance license was republished with the same content ID but different rights, the EUL returned may not be the one sought. If it is not, increment the *uIndex* parameter and call **DRMEnumerateLicense** again. You can continue iterating until you find the correct EUL or the function returns **E_DRM_NO_MORE_DATA**.

Perform the following steps to enumerate a machine certificate:

1. Call [DRMCreateClientSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateclientsession) or [DRMCreateLicenseStorageSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreatelicensestoragesession) to create a session object. The type of session created determines the nature of the value returned in the *pfSharedFlag* parameter. For more information, see the **DRM_EL_MACHINE** constant in the *uFlags* parameter.
2. Set the *uIndex* parameter to zero or one and the *uFlags* parameter to **DRM_EL_MACHINE** and call **DRMEnumerateLicense**.

Perform the following steps to enumerate rights account certificates (RACs):

1. Call [DRMCreateClientSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateclientsession) to create a client session.
2. Set the *uIndex* parameter to zero and the *uFlags* parameter to **DRM_EL_GROUPIDENTITY** and call **DRMEnumerateLicense**.
3. Examine the RAC returned. If it is not the one sought, increment *uIndex* and call **DRMEnumerateLicense** again. You can continue iterating until you find the correct RAC or the function returns **E_DRM_NO_MORE_DATA**.

Perform the following steps to enumerate client licensor certificates (CLCs):

1. Call [DRMCreateClientSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateclientsession) to create a client session.
2. Set the *uIndex* parameter to zero and the *uFlags* parameter to **DRM_EL_CLIENTLICENSOR** and call **DRMEnumerateLicense**.
3. Examine the CLC returned. If it is not the one sought, increment *uIndex* and call **DRMEnumerateLicense** again. You can continue iterating until you find the correct CLC or the function returns **E_DRM_NO_MORE_DATA**.

Perform the following steps to enumerate issuance license templates:

1. Call [DRMCreateClientSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateclientsession) to create a client session.
2. Set the *uIndex* parameter to zero and the *uFlags* parameter to **DRM_EL_ISSUANCELICENSE_TEMPLATE** and call **DRMEnumerateLicense**.
3. Examine the template. If it is not the one sought, increment *uIndex* and call **DRMEnumerateLicense** again. You can continue iterating until you find the correct template or the function returns **E_DRM_NO_MORE_DATA**.

Perform the following steps to enumerate revocation lists:

1. Call [DRMCreateClientSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateclientsession) or [DRMCreateLicenseStorageSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreatelicensestoragesession) to create a session object. Use the client session handle to retrieve revocation lists for rights account or client licensor certificates. Use the license storage session handle to retrieve the revocation lists for end user licenses.
2. Set the *uIndex* parameter to zero and the *uFlags* parameter to **DRM_EL_REVOCATIONLIST** and call **DRMEnumerateLicense**.
3. If the revocation list is not the one sought, increment *uIndex* and call **DRMEnumerateLicense** again. You can continue iterating until you find the correct list or the function returns **E_DRM_NO_MORE_DATA**.

You must call **DRMEnumerateLicense** twice to retrieve one license. Set the *wszCertificateData* to **NULL** on the first call to retrieve the required buffer size. Allocate memory and call **DRMEnumerateLicense** again. This is illustrated by the following example.

```cpp
// Call DRMEnumerateLicense with the wszCertificateData parameter set
// to NULL.
hr = DRMEnumerateLicense(
         hClient,                          // Client session handle
         DRM_EL_SPECIFIED_CLIENTLICENSOR,  // Flags
         0,                                // Index
         &fShared,                         // Shared license
         &uiClientLicensorCertLength,      // Certificate length
         NULL                              // Certificate
         );

if ( FAILED( hr ) && ( E_DRM_NO_MORE_DATA != hr ) )
{
   goto e_Exit;
}

// There are no client licensor certificates. Acquire one.
else if ( E_DRM_NO_MORE_DATA == hr )
{
    // TODO: Acquire a client licensor certificate.
}

// A client licensor certificate was found. Allocate memory and
// call DRMEnumerateLicense again.
else
{

   wszClientLicensorCert = new WCHAR[ uiClientLicensorCertLength ];
   if ( NULL == wszClientLicensorCert )
   {
      hr = E_OUTOFMEMORY;
      goto e_Exit;
   }

   hr = DRMEnumerateLicense(
         hClient,                          // Client session handle
         DRM_EL_SPECIFIED_CLIENTLICENSOR,  // Flags
         0,                                // Index
         &fShared,                         // Shared license
         &uiClientLicensorCertLength,      // Certificate length
         wszClientLicensorCert             // Certificate
         );

   if ( FAILED( hr ) )
   {
      goto e_Exit;
   }
}

e_Exit:

    if ( NULL != hClient )
    {
        hr = DRMCloseSession( hClient );
    }

    if ( NULL != wszUserId )
    {
        delete [] wszUserId;
    }

    if ( NULL != wszLicensingSvr )
    {
        delete [] wszLicensingSvr;
    }

    if ( NULL != wszClientLicensorCert )
    {
        delete [] wszClientLicensorCert;
    }

    return hr;

```

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[OfflineSigning_GetCertificate.cpp](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/offlinesigning-getcertificate-cpp)