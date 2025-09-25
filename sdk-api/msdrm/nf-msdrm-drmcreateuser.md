# DRMCreateUser function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMCreateUser** function creates a user that
will be granted a right.

## Parameters

### `wszUserName` [in]

A null-terminated string that identifies a user or group of users (see Remarks). This parameter is often an
email address. When the user created is passed in as *hOwner* to
[DRMCreateIssuanceLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateissuancelicense), this value is
attached to the Owner node in the license XrML. For more information about possible values for this parameter,
see the *wszUserIdType* parameter.

### `wszUserId` [in]

A null-terminated string that identifies a user that will be granted a right. This parameter can be a
Passport ID (PUID), Windows ID [security ID](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/s-gly) (SID), or
**NULL**. If this parameter is **NULL**,
*wszUserIdType* must contain "Unspecified". This ID is verified by the
Active Directory Rights Management Services system. For more information about possible values for this
parameter, see the *wszUserIdType* parameter.

### `wszUserIdType` [in]

The user ID type. This parameter can be one of the following values.

#### "Windows"

For this value, *wszUserName* and *wszUserId* can contain
the following.

##### wszUserName

Fully qualified SMTP address. Can be **NULL** if
*wszUserId* contains a SID.

##### wszUserId

Optional SID (used for decorative purposes only; not verified). If not given, the license records
"Unspecified".

#### "Passport"

For this value, *wszUserName* and *wszUserId* can contain
the following.

##### wszUserName

Fully qualified SMTP address. Required in all cases.

##### wszUserId

Optional PUID (used for decorative purposes only; not verified). If not given, the license records
"Unspecified".

#### "Unspecified"

For this value, *wszUserName* and *wszUserId* can contain
the following.

##### wszUserName

Fully qualified SMTP address. Required in all cases.

##### wszUserId

**NULL** (see Remarks).

#### "Internal"

For this value, *wszUserName* and *wszUserId* can contain
the following.

##### wszUserName

**NULL**

##### wszUserId

One of the following:

###### "Anyone"

A license will be granted to anyone who requests one, but it will be attached to the requesting
user.

###### "Owner"

A license will be granted to the owner, specified in
[DRMCreateIssuanceLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateissuancelicense).

#### "Federation"

For this value, *wszUserName* and *wszUserId* can contain
the following.

##### wszUserName

Fully qualified SMTP address. Can be **NULL** if *wszUserId* contains a SID.

##### wszUserId

Optional SID (used for decorative purposes only; not verified). If not given, the license records
"Unspecified".

### `phUser` [out]

A pointer to the handle of the created user. Call
[DRMClosePubHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosepubhandle) to close the handle.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For
a list of common error codes, see
[Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

At license request time, a user must present a rights account certificate identifying themselves by SID or PUID
if the user ID is WINDOWS or PASSPORT. If the user ID type is UNSPECIFIED (that is, if you do not know if it will
be Windows, Passport, or some other type), you can simply enter an email address of a client, and the AD RMS
system will use the email address alone to verify identity. However, this method is much less secure.

Windows authorization is used when a client is within an enterprise with its own license server (typically this
occurs over a LAN or Virtual Private Network). When a client will be requesting a use license from a server
outside an enterprise (typically over the Internet), you should use Passport authorization. To use Passport
authorization on your AD RMS service, go to the AD RMS Global Administration webpage, view the
**Trust Policies** page, and then click **Trust Passport RACs**.
You may mix Windows and Passport users in a single issuance license.

If you want to create an issuance license for a group of people under an email distribution list (such as
marketing@contoso.com), insert the fully qualified distribution list name into
*wszUserName*, and leave *wszUserId* empty. The server will
expand the distribution list when obtaining the use license. Note that this can cause a performance lag if the
distribution list contains several nested distribution lists within it.

Call [DRMClosePubHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosepubhandle) to close the handle of the
user object created by calling this function.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[Creating and Using Issuance Licenses](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/creating-and-using-issuance-licenses)

[OnlineSigning_GetUnsignedIL.cpp](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/onlinesigning-getunsignedil-cpp)