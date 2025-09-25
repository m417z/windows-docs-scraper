# DRMSetMetaData function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMSetMetaData** function adds application-specific metadata to an issuance license.

## Parameters

### `hIssuanceLicense` [in]

The handle of the issuance license to which the metadata will be added.

### `wszContentId` [in]

A pointer to a null-terminated Unicode string that uniquely identifies an item of content. The string can contain up to 40 characters plus a terminating null character. We recommend that you use **CoCreateGUID** to create a GUID. For more information about content IDs, see Remarks.

### `wszContentIdType` [in]

A pointer to a null-terminated Unicode string that specifies the type of identifier represented by the *wszContentId* parameter. Possible examples include "MSGUID", "ISBN", "CatalogNumber", and any other that you consider appropriate.

### `wszSKUId` [in, optional]

A pointer to a null-terminated Unicode string that contains an optional identifier. The string can contain up to 40 characters plus a terminating null character. The SKU ID is optional and allows for further content identification beyond that provided by the required content ID. If *wszSKUIdType* is specified, the *wszSKUId* parameter must be specified. Otherwise, it can be **NULL**.

### `wszSKUIdType` [in, optional]

A pointer to a null-terminated Unicode string that contains the type of identifier represented by the *wszSKUId* parameter. If *wszSKUId* is specified, the *wszSKUIdType* parameter must be specified. Otherwise, it can be **NULL**.

### `wszContentType` [in, optional]

A pointer to a null-terminated Unicode string that contains application-defined information about the content. Examples include "Financial Statement", "Source Code", "Office Document", and any other that you consider appropriate. This parameter is optional and can be **NULL**.

### `wszContentName` [in, optional]

A pointer to a null-terminated Unicode string that contains a display name for the content. This parameter is optional and can be **NULL**.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The **DRMSetMetaData** function is typically called after [DRMCreateIssuanceLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateissuancelicense) to set the content ID, name, and type in an issuance license for a specific item of content. The function is also called before [DRMCreateBoundLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateboundlicense) or [DRMEnumerateLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmenumeratelicense).

Content IDs are created and set in issuance licenses by a publishing application. For example, the application can call [DRMCreateIssuanceLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateissuancelicense) to create a new issuance license. It can then call **CoCreateGUID** to create a unique ID and **DRMSetMetaData** to associate the ID with the license. The AD RMS client places the ID in the <WORK> node of the issuance license as shown by the following diagram. For more information, see [Creating an Issuance License](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/creating-an-issuance-license).

``` syntax
<WORK>
   <OBJECT type="Microsoft Office Document">
      <ID type="MSGUID">{AEADA9BD84F246BD92385A611D624A02}</ID>
      <NAME>Microsoft Office Document</NAME>
   </OBJECT>
    .
    .
    .
</WORK>
```

After an issuance license has been created, a consuming application can use it to acquire an end–user license. For more information, see [DRMAcquireLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmacquirelicense). The appropriate <WORK> nodes and their respective content IDs are copied from the issuance license to the end–user license.

Once an end–user license has been acquired, consuming applications internally use the content ID to bind to that license. For more information, see [DRMCreateBoundLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateboundlicense). Binding verifies the license chain, principals, and environment, and removes all rights that do not apply to the specified user. The bound license can then be used to decrypt protected content.

Finally, the content ID can be used to enumerate end–user licenses. For more information, see [DRMEnumerateLicense](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmenumeratelicense) and [DRMCreateLicenseStorageSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreatelicensestoragesession). The content ID is used to locate an end–user license in the license store.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMGetMetaData](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetmetadata)