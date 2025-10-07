# DRMCreateIssuanceLicense function

## Description

[The AD RMS SDK leveraging functionality exposed by the client in Msdrm.dll is available
for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2,
Windows 7, Windows Server 2012, and Windows 8. It may be altered or
unavailable in subsequent versions. Instead, use
[Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),
which leverages functionality exposed by the client in Msipc.dll.]

The **DRMCreateIssuanceLicense** function
creates an [issuance license](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/i-gly) from scratch, from a template, or from a signed issuance license.

## Parameters

### `pstTimeFrom` [in]

The starting UTC validity time for the license. If this value is **NULL**, the *pstTimeUntil* parameter must also be **NULL**. If both parameters are not **NULL**, **E_DRM_INVALID_TIMEINFO** is returned if the range time is logically inconsistent. For example, *pstTimeFrom* cannot be later than *pstTimeUntil*.

### `pstTimeUntil` [in]

The ending UTC validity time for the license. If this value is **NULL**, the *pstTimeFrom* parameter must also be **NULL**. If both parameters are not **NULL**, **E_DRM_INVALID_TIMEINFO** is returned if the range time is logically inconsistent. For example, *pstTimeFrom* cannot be later than *pstTimeUntil*.

### `wszReferralInfoName` [in]

Nonsilent license acquisition is not supported; set this parameter to **NULL**.

For Rights Management Services (RMS) client 1.0, this parameter is a pointer to a null-terminated Unicode string that contains the display name for the URL in *wszReferralInfoURL*. This parameter is optional and can be **NULL**.

### `wszReferralInfoURL` [in]

Nonsilent license acquisition is not supported; set this parameter to **NULL**.

For RMS client 1.0, this parameter is a pointer to a null-terminated Unicode string that contains the URL where an application should go to request a license for the content nonsilently. This should be an HTML page that hosts the ActiveX control. This parameter is optional and can be **NULL**.

### `hOwner` [in, optional]

A handle to the user that owns the issuance license. The handle is created by calling the [DRMCreateUser](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateuser) function. The owner is identified under the **Owner** node in the issuance license XrML. This parameter is optional and can be **NULL**.

Do not confuse the owner of an issuance license with a user who has been granted the OWNER right. Ownership of an issuance license does not automatically grant any rights to use or modify content. Specifying a value for the optional *hOwner* parameter merely enables an application to identify the content owner or author. The ID is added as metadata to the license. The OWNER right, on the other hand, grants a user the authority to exercise all rights contained in the license. Granting yourself (or anyone else) the OWNER right must be done explicitly by using [DRMAddRightWithUser](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmaddrightwithuser). Zero, one, or more users can be granted the OWNER right, which never expires.

If specified, the issuance license owner is added as metadata beneath the \<WORK> node of the license.

```
<WORK>
  <OBJECT type="contentType">
    <ID type="contentIdType">contentId</ID>
    <NAME>contentName</NAME>
  </OBJECT>
  <METADATA>
    <OWNER>
      <OBJECT>
        <ID type="Windows"/>
        <NAME>david@contoso.com</NAME>
      </OBJECT>
    </OWNER>
  </METADATA>
  ...

```

If granted, the OWNER right is added as an attribute of the \<RIGHT> element in the license XrML.

```
<WORK>
  ...
  <RIGHTSGROUP name="MainRights">
    <RIGHTSLIST>
      <VIEW>
        ...
      </VIEW>
      <RIGHT name="OWNER">
        <CONDITIONLIST>
          ...
        </CONDITIONLIST>
      </RIGHT>
    </RIGHTSLIST>
  </RIGHTSGROUP>
```

**Note** In the case where you set *hOwner* to the license author and use a template where you check the **Grant Owner (author) full control right with no expiration** check box, the license author can subsequently get an end-user license with Owner rights. See [Understanding XrML Rights](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/understanding-xrml-rights) for more information.

### `wszIssuanceLicense` [in]

A pointer to a null-terminated Unicode string that contains an issuance license template or a signed issuance license. You can call the [DRMGetIssuanceLicenseTemplate](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetissuancelicensetemplate) function to retrieve a template. If this parameter is **NULL**, an issuance license is created.

### `hBoundLicense` [in]

A handle to a bound license that contains the VIEWRIGHTSDATA, EDITRIGHTSDATA or OWNER right, which allows an application to reuse rights data or reuse the content key from a previous issuance license. This parameter is optional and can be **NULL**. For further information about rights, see [Understanding XrML Rights](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/understanding-xrml-rights).

**Note** If your intent is to create a new issuance license, but you want to use the content key from the original signed issuance license, ensure that the *hBoundLicense* you pass in to **DRMCreateIssuanceLicense** is bound to either the OWNER or EDITRIGHTSDATA right. In a subsequent call to [DRMGetSignedIssuanceLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetsignedissuancelicense), pass in the issuance license handle obtained from **DRMCreateIssuanceLicense** and the DRM_REUSE_KEY flag in order to reuse the content key.

### `phIssuanceLicense` [out]

A pointer to a [DRMPUBHANDLE](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/drmpubhandle) that receives the handle to the new issuance license.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

An issuance license is a list of rights, users, metadata, and other information that specifies how a specific user on a specific computer is able to use the specified content. This issuance license must be signed by using the [DRMGetSignedIssuanceLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetsignedissuancelicense) function or the [AcquireIssuanceLicense](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/-acquireissuancelicense) SOAP method. The resulting signed issuance license is given to a potential end user who must then request an [end-user license](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/e-gly) by calling the [DRMAcquireLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmacquirelicense) function. An application may request an end-user license on behalf of another end user by using the [AcquirePreLicense](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/-acquireprelicense) SOAP method. It is only the end-user license that allows an application to exercise the rights that have been granted.

This function allows you to create licenses in three different ways.

| *wszIssuanceLicense* value | *hBoundLicense* value | Description |
| --- | --- | --- |
| An unsigned issuance license from a file or an issuance license handle passed into [DRMGetIssuanceLicenseTemplate](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetissuancelicensetemplate) | **NULL** | Use to create an issuance license from a template. The new issuance license contains information from the old issuance license (the list follows this table), but it does not reuse the content key. |
| A signed issuance license | A handle to the license bound by the OWNER or VIEWRIGHTSDATA right | Use to reuse rights information (the list follows this table). |
| **NULL** | **NULL** | Use to create an issuance license from scratch. It includes no users, rights, metadata, or policies. |

When an issuance license (signed or unsigned) is passed in, the following data is reused:

* Users (from [DRMCreateUser](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateuser))
* Rights (from [DRMCreateRight](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateright))
* Application-specific data (from [DRMSetApplicationSpecificData](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmsetapplicationspecificdata))
* Metadata (from [DRMSetMetaData](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmsetmetadata))
* Name and description (from [DRMSetNameAndDescription](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmsetnameanddescription))
* Revocation point (from [DRMSetRevocationPoint](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmsetrevocationpoint))
* Usage policy (from [DRMSetUsagePolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmsetusagepolicy))

Because nonsilent license acquisition is not supported, *wszReferralInfoName* and *wszReferralInfoURL* should be **NULL**.

For RMS client 1.0, the referral point described by *wszReferralInfoName* and *wszReferralInfoURL* is used as a backup URL if a call to the URL specified in the license header fails. This method allows a caller to define a display name and a URL to a site that handles nonsilent license requests for the content.

The *hBoundLicense* parameter allows an application to be able to reuse data from an existing issuance license. This is done by having the publishing application create a VIEWRIGHTSDATA right and grant it to any application allowed to reuse the issuance license information. However, because this involves binding to a license, which is a task that cannot be done without using a [lockbox](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/l-gly), this value should be **NULL** for server applications that do not use a lockbox.

The purpose of a URL cannot be verified by any part of a client or Active Directory Rights Management Services system. It would be possible for a malicious publisher to include a harmful URL address in an issuance license, although the issuance license creator would need a valid licensed Active Directory Rights Management Services system to do so.

One problem that can arise when creating issuance licenses with short validity times is the problem of clock skew. Clock skew is when the publishing computer's clock and the end user's computer clock are not exactly aligned. Clock skew can cause issuance license signing attempts to fail. For more information, see [Clock Skew](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/clock-skew).

Call [DRMClosePubHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosepubhandle) to close the issuance license handle created by calling this function.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[Creating and Using Issuance Licenses](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/creating-and-using-issuance-licenses)