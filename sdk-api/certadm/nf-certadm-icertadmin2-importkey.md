# ICertAdmin2::ImportKey

## Description

The **ImportKey** method adds an encrypted key set to an item in the Certificate Services database. The key set is encrypted to one or several key recovery agent (KRA) certificates.

## Parameters

### `strConfig` [in]

String value that represents a valid configuration string for the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) in the form COMPUTERNAME\CANAME, where COMPUTERNAME is the Certificate Services server's network name, and CANAME is the common name of the CA, as entered during Certificate Services setup. For information about the configuration string name, see
[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig).

**Important** **ImportKey** does not clear the internal cache when the configuration string is changed. When you change the configuration string for the CA, you must instantiate a new [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2) object and call this method again with the new configuration string.

### `RequestId` [in]

**LONG** value that represents the [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) ID in the Certificates Services database. If the serial number (passed in as *strCertHash*) is to be used instead of the request ID, use zero for this value.

### `strCertHash` [in]

String value that represents the certificate hash. For *strCertHash* to be used, you must specify a value of zero for *RequestId*.

### `Flags` [in]

Specifies the format of the key. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CR_IN_BASE64HEADER** | BASE64 format with begin or end. |
| **CR_IN_BASE64** | BASE64 format without begin or end. |
| **CR_IN_BINARY** | Binary format. |

Additionally, the following value can be combined with the format value by using a bitwise-**OR** operation.

| Value | Meaning |
| --- | --- |
| **IKF_OVERWRITE** | Any existing KRA encoded information is overwritten. |

### `strKey` [in]

String value that represents the KRA key information.

## See also

[ICertAdmin2](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2)