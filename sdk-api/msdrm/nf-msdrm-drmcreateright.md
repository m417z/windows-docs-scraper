# DRMCreateRight function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMCreateRight** function creates an XrML right that will define a right granted to a user or group.

## Parameters

### `wszRightName` [in]

A pointer to a null-terminated Unicode string that contains the name of a user-defined or standard XrML (version 1.2) right. For more information, see [Official Template XrML](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/official-template-xrml).

### `pstFrom` [in]

A pointer to a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that contains the time, in UTC time, when this right will become valid. For more information, see Remarks. Both *pstFrom* and *pstUntil* must be specified, or both must be **NULL**.

### `pstUntil` [in]

A pointer to a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that contains the time, in UTC time, when this right will expire. For more information, see Remarks. Both *pstFrom* and *pstUntil* must be specified, or both must be **NULL**.

### `cExtendedInfo` [in]

The number of elements in the *pwszExtendedInfoName* and *pwszExtendedInfoValue* arrays. If this parameter is zero, then both the *pwszExtendedInfoName* and *pwszExtendedInfoValue* parameters must be **NULL**.

### `pwszExtendedInfoName` [in]

An array of null-terminated Unicode string pointers that contains the names of extended information data. Each name in this array must be unique. The **cExtendedInfo** parameter contains the number of elements in this array.

### `pwszExtendedInfoValue` [in]

An array of null-terminated Unicode string pointers that contains the values of the extended information items. The **cExtendedInfo** parameter contains the number of elements in this array.

### `phRight` [out]

A pointer to a handle that receives the handle of the created right. This handle can be used with the [DRMAddRightWithUser](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmaddrightwithuser) function to bind the right to a user. Call [DRMClosePubHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosepubhandle) to close the handle.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Determining which rights a user can be granted is the responsibility of the application. The only right that Active Directory Rights Management Services enforces is EDIT, which grants the user the right to modify content.

A right can have any name that can be validly expressed in XML.

The *pstFrom* and *pstUntil* parameters specify the start and end validity times of the right. These parameters must either both be specified, or both be **NULL**. An application cannot set only one validity time.

One problem that can arise when creating licenses with short validity times is the problem of clock skew. *Clock skew* is when the publishing computer's clock and the end user's computer clock are not exactly aligned. Clock skew can cause attempts to exercise rights to fail. For more information, see [Clock Skew](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/clock-skew).

The *pwszExtendedInfoName* and *pwszExtendedInfoValue* parameters are pointers to two parallel arrays that associate name-value pairs that hold additional right-specific information. These name-value pairs can specify any additional information you want, and they are retrieved by index number by using [DRMGetRightExtendedInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetrightextendedinfo). Extended information items are optional, but if a name or value is given, the corresponding item in the other array cannot be **NULL**.

Call [DRMClosePubHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmclosepubhandle) to close the handle of the right created by calling this function.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[Creating and Using Issuance Licenses](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/creating-and-using-issuance-licenses)

[OnlineSigning_GetUnsignedIL.cpp](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/onlinesigning-getunsignedil-cpp)