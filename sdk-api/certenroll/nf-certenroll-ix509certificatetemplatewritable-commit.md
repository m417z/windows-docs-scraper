# IX509CertificateTemplateWritable::Commit

## Description

The **Commit** method deletes a template from or saves it to Active Directory.

## Parameters

### `commitFlags` [in]

A [CommitTemplateFlags](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-committemplateflags) enumeration value that specifies how to save or delete the template. This must be one of the following values.

| Value | Meaning |
| --- | --- |
| **CommitFlagSaveTemplateGenerateOID** | Save the template and create an object identifier for it. |
| **CommitFlagSaveTemplateUseCurrentOID** | Not used. |
| **CommitFlagSaveTemplateOverwrite** | Not used. |
| **CommitFlagDeleteTemplate** | Delete the template. |

### `strServerContext` [in]

A **BSTR** variable that contains the DNS name of the Active Directory server to which the changes will be applied. If this value is **NULL**, the changes will be applied to the default domain controller.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **CRYPT_E_EXISTS** | **CommitFlagSaveTemplateGenerateOID** was specified in the *commitFlags* argument but a template with a matching common name or a matching object identifier (OID) already exists. |
| **CRYPT_E_NOT_FOUND** | *CommitFlagDelete* was specified in the *commitFlags* argument and a template with the same Common Name was found but the OID did not match. |
| **E_ACCESSDEINED** | The caller does not have the appropriate permission to save or delete a template. The caller must have write and delete permission on the template container and template objects in Active Directory. If the caller has delete permission on the template container and objects but does not have delete permission on the OID container and objects, the template will be deleted but the OID will not be. |
| **E_NOTIMPL** | Either **CommitFlagSaveTemplateUseCurrentOID** or **CommitFlagSaveTemplateOverwrite** was specified in the *commitFlags* argument. These values are not currently used. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | *CommitFlagDelete* was specified in the *commitFlags* argument but a template having a matching Common Name (CN) could not be found. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The [Commit](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificatetemplatewritable-commit) method is not supported for default templates. |
| **OLE_E_BLANK** | The [IX509CertificateTemplateWritable](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificatetemplatewritable) object has not been initialized. |

## Remarks

When **CommitFlagSaveTemplateGenerateOID** is specified in the *commitFlags* argument, this method will not succeed unless the template and OID containers have already been created. These containers can be created in any of the following ways:

* Installing an enterprise certification authority on the server.
* Launching the Certtmpl.msc snap-in.
* Using the **Certutil.exe -installDefaultTemplates** command to install the default templates.

## See also

[IX509CertificateTemplateWritable](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificatetemplatewritable)