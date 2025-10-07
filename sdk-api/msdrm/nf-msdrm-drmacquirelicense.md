# DRMAcquireLicense function

## Description

[The AD RMS SDK leveraging functionality exposed by the client in Msdrm.dll is available
for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2,
Windows 7, Windows Server 2012, and Windows 8. It may be altered or
unavailable in subsequent versions. Instead, use
[Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),
which leverages functionality exposed by the client in Msipc.dll.]

The **DRMAcquireLicense** function attempts to acquire an end-user license or client licensor certificate asynchronously.

## Parameters

### `hSession` [in]

A handle to a client or license storage session.

A client session handle is obtained by using the
[DRMCreateClientSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateclientsession) function. In this case,
a client licensor certificate is acquired. The application callback function specified in the **DRMCreateClientSession** function will be called with the [DRM_MSG_ACQUIRE_CLIENTLICENSOR](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/drm-msg-acquire-clientlicensor) message to provide status feedback.

A license storage session handle is obtained by calling the [DRMCreateLicenseStorageSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreatelicensestoragesession) function. In this case, an end-user license is acquired. The application callback function specified in the client session passed in the *hClient* parameter of the **DRMCreateLicenseStorageSession** function will be called with the [DRM_MSG_ACQUIRE_LICENSE](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/drm-msg-acquire-license) message to provide status feedback.

### `uFlags` [in]

Specifies options for the function call. This parameter can be zero or a combination of one or more of the following flags.

#### DRM_AL_NONSILENT ()

Nonsilent license acquisition is not supported. **DRMAcquireLicense** returns **E_INVALIDARG** if this flag is set.

For Rights Management Services (RMS) client 1.0, acquire the license nonsilently. The default is silent license acquisition.

#### DRM_AL_NOPERSIST ()

Store the license only in the temporary (in-memory) license store. The default is to store the license in the permanent license store.

#### DRM_AL_CANCEL ()

Cancel the previous request.

#### DRM_AL_FETCHNOADVISORY ()

Do not acquire revocation lists required by the license. The default action is to acquire all revocation lists that a returned license requires. All revocation lists must still be registered, however, by using the [DRMRegisterRevocationList](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmregisterrevocationlist) function.

#### DRM_AL_NOUI ()

This flag suppresses the Windows network authentication dialog box. If the license request is denied because the user does not have permission, this flag will prevent the network authentication dialog box from being displayed. This is useful when attempting to handle license acquisition on a background or other non-user interface thread because you can avoid potentially confusing dialog boxes. If authentication does fail, and this flag is specified, the callback that is associated with the request will immediately receive an error of **E_DRM_LICENSEACQUISITIONFAILED**.

If *hSession* is a client session handle, this flag is ignored.

### `wszGroupIdentityCredential` [in]

An optional [rights account certificate](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/r-gly) (RAC). If this is not used, this function will check the license store for a RAC that matches the license used to create *hSession*. If none is found, this function will fail.

### `wszRequestedRights` [in]

This parameter is reserved and must be **NULL**.

### `wszCustomData` [in]

Optional application-specific data that might be required for a license. This must be a valid XML string. After returning control to the caller, this function creates a license request by using the application-specific data specified here.

### `wszURL` [in]

A license acquisition URL. This parameter is required when a client licensor certificate is being acquired and optional when an end-user license is being acquired. The URL can be used for both silent and nonsilent license acquisition. When present, this URL overrides the URL specified in the license that was used to create the license storage session passed into *hSession*.

A license may hold multiple license acquisition URLs, but only the first is used by default. To use any of the other URLs specified, you must parse the license. For more information, see the Remarks section.

### `pvContext` [in]

A 32-bit, application-defined value that is sent in the *pvContext* parameter of the callback function. This value can be a pointer to data, a pointer to an event handle, or whatever else the custom callback function is designed to handle. For more information, see [Callback Prototype](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrmdefs/nc-msdrmdefs-drmcallback).

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

This function is used for retrieving an end-user license or client licensor certificate asynchronously. There
is no synchronous version of this function. To cancel a license request in process, call
**DRMAcquireLicense** again with
**DRM_AL_CANCEL** specified in *uFlags*. The progress of this
function, and any data returned, will be returned to the callback function (see
[Creating a Callback Function](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/creating-a-callback-function)).

If the retrieved end-user license requires any revocation lists, these are acquired at the same time, unless
**DRM_AL_FETCHNOADVISORY** is specified in *uFlags*. A failure to
retrieve required revocation lists will be indicated by **E_DRM_NO_CONNECT**. The
application must register any retrieved lists by using
[DRMRegisterRevocationList](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmregisterrevocationlist).

This function can occur silently or nonsilently.

**Note** Nonsilent license acquisition is supported only in RMS client 1.0. Effective with RMS client 1.0 SP1,
nonsilent license acquisition is no longer supported, and MSDRMCtrl.dll is not shipped.

In nonsilent license acquisition, a license acquisition URL is returned to the callback function in a
[DRM_LICENSE_ACQ_DATA](https://learn.microsoft.com/windows/desktop/api/msdrmdefs/ns-msdrmdefs-drm_license_acq_data) structure. The application then
opens a web browser that is directed to a URL that specifies an HTML page that contains the ActiveX control in
MSDRMCtrl.dll. The page is used to obtain additional information, such as a credit card number, and
then calls the ActiveX control's **AcquireLicense**
function, which causes license acquisition to proceed as normal. The license can only be returned to the
permanent license store.

In silent license acquisition, no webpages need be opened, and license acquisition progress is noted in the
application's callback function.

The retrieved license is added to the temporary or permanent license store, depending on whether
**DRM_AL_NOPERSIST** is specified or not. In nonsilent license acquisition, the acquired
license cannot be added to the temporary license store, only to the permanent license store, where it must be
retrieved by using [DRMEnumerateLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmenumeratelicense). The
following list describes possible combinations of license acquisition type with license store type.

| License store | Silent acquisition | Nonsilent acquisition |
| --- | --- | --- |
| Temporary | **DRM_AL_NOPERSIST** | Not possible |
| Permanent | No flags | **DRM_AL_NONSILENT** |

**Note** Although the issuance license is signed and protected by encryption, it would be possible for a malicious publisher to include the URL of a malicious website; there is no way to verify the nature of this URL in advance.

AD RMS allows an administrator to specify an extranet licensing URL in addition to an internal (intranet) URL. Each URL is copied into the license under a separate \<DISTRIBUTIONPOINT> node with the internal URL appearing first. This is illustrated by the following example.

```xml

      <DISTRIBUTIONPOINT>
      - <OBJECT type="License-Acquisition-URL">
          <ID type="MS-GUID">
            {0F45FD50-383B-43EE-90A4-ED013CD0CFE5}
          </ID>
          <NAME>DRM Server Cluster</NAME>
          <ADDRESS type="URL">
            https://corprights/_wmcs/licensing
          </ADDRESS>
        </OBJECT>
      </DISTRIBUTIONPOINT>
      <DISTRIBUTIONPOINT>
      - <OBJECT type="Extranet-License-Acquisition-URL">
          <ID type="MS-GUID">
            {94BF969A-CA04-44d6-AA96-51071281FAG2}
          </ID>
          <NAME>DRM Server Cluster</NAME>
          <ADDRESS type="URL">
            https://corprights.example.com/_wmcs/licensing
          </ADDRESS>
        </OBJECT>
      </DISTRIBUTIONPOINT>

```

Multiple URLs are often specified so that users can access protected content both at work and at home. The second URL provides a license acquisition point that does not require the user working at home to log on to the corporate network. The **DRMAcquireLicense** function, however, uses the first URL by default. Therefore, to allow the consumer to use an alternate URL, your application must parse the license.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)