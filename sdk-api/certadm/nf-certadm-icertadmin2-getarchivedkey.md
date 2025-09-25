# ICertAdmin2::GetArchivedKey

## Description

The **GetArchivedKey** method retrieves an archived key recovery [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly). This method was first defined in the [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin) interface.

## Parameters

### `strConfig` [in]

Represents a valid configuration string for the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) in the form *ComputerName*\*CAName*, where *ComputerName* is the Certificate Services server's network name, and *CAName* is the common name of the CA, as entered during Certificate Services setup. For information about the configuration string name, see
[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig).

**Important** **GetArchivedKey** does not clear the internal cache when the configuration string is changed. When you change the configuration string for the CA, you must instantiate a new [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2) object and call this method again with the new configuration string.

### `RequestId` [in]

Represents the [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) ID in the Certificates Services database.

### `Flags` [in]

The following flags can be used to specify the format of the returned BLOB.

| Value | Meaning |
| --- | --- |
| **CR_OUT_BASE64** | BASE64 without BEGIN/END |
| **CR_OUT_BASE64HEADER** | BASE64 with BEGIN CERTIFICATE and END CERTIFICATE |
| **CV_OUT_BINARY** | Binary |

### `pstrArchivedKey` [out]

A pointer to the string that represents the retrieved archived [key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly). When you have finished using this string, it is the responsibility of the caller to free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

## Return value

### C++

The return value is an **HRESULT**. A value of **S_OK** indicates the method was successful.

### VB

A string that contains the retrieved archived key BLOB.

## Remarks

An archived key is encrypted in a PKCS #7 to the key recovery agent certificate or certificates, and is stored in the Certificate Services database in that form. This method retrieves the encrypted PKCS #7 from the Certificate Services database, wraps it in a signed PKCS #7 which contains the user certificate and chain, the key recovery agent certificate or certificates, and the certification authority's signing certificate and chain. An authenticated attribute contains a certificate used to uniquely identify the user certificate.