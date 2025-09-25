# ICertAdmin2::GetConfigEntry

## Description

The **GetConfigEntry** method retrieves configuration information for a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA).

## Parameters

### `strConfig` [in]

String value that represents a valid configuration string for the CA in the form COMPUTERNAME\CANAME, where COMPUTERNAME is the Certificate Services server's network name, and CANAME is the common name of the CA, as entered during Certificate Services setup. For information about the configuration string name, see
[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig). This parameter can be an empty string, in which case the function retrieves configuration information that is not specific to a CA. This parameter cannot be **NULL**.

**Important** **GetConfigEntry** does not clear the internal cache when the configuration string is changed. When you change the configuration string for the CA, you must instantiate a new [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2) object and call this method again with the new configuration string.

### `strNodePath` [in]

String value that represents the node path for the configuration information. This parameter can be an empty string, in which case the function retrieves configuration information from the path identified by *strConfig*. This parameter cannot be **NULL**.

### `strEntryName` [in]

String value that represents the name of the entry whose information is being retrieved. This value can be an empty string, in which case all of the entry names are retrieved. This parameter cannot be **NULL**.

### `pvarEntry` [out]

A pointer to a **VARIANT** that receives the requested information.

## Return value

### C++

If the function is successful, the return value is S_OK.

If the function fails, the return value is an **HRESULT** that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is a **Variant** that represents the retrieved configuration information.

## Remarks

 The configuration information is stored in the registry under the following path.

**HKEY_LOCAL_MACHINE**\**SYSTEM**\**CurrentControlSet**\**Services**\**CertSvc**\**Configuration**\*[CASANITIZEDNAME]*\*[strNodePath]*\*[strEntryName]*Where *CASANITIZEDNAME* is the [sanitized name](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) for the CA. For more information about sanitized names, see [ICertConfig2::GetConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertconfig-getconfig).

## See also

[ICertAdmin2](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2)