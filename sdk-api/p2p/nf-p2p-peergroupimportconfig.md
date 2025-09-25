# PeerGroupImportConfig function

## Description

The **PeerGroupImportConfig** function imports a peer group configuration for an identity based on the specific settings in a supplied XML configuration string.

## Parameters

### `pwzXML` [in]

Specifies a Unicode string that contains a previously exported (using [PeerGroupExportConfig](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupexportconfig)) peer group configuration. For the specific XML format of the string, see to the Remarks section of this topic. This parameter is required.

### `pwzPassword` [in]

Specifies the password used to access the encrypted peer group configuration data, as a Unicode string. This parameter is required.

### `fOverwrite` [in]

If true, the existing group configuration is overwritten. If false, the group configuration is written only if a previous group configuration does not exist. The default value is false. This parameter is required.

### `ppwzIdentity` [out]

Contains the peer identity returned after an import completes. This parameter is required.

### `ppwzGroup` [out]

Contains a peer group peer name returned after an import completes. This parameter is required.

## Return value

Returns **S_OK** if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform a specified operation. |
| **PEER_E_ALREADY_EXISTS** | A peer group configuration already exists, and *fOverwrite* is set to false. |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## Remarks

To generate a peer group configuration, call [PeerGroupExportConfig](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupexportconfig), pass in an identity to export, a password, and a handle to the peer group.

The configuration XML string appears in the following format:

``` syntax
<PEERGROUPCONFIG VERSION="1.0">
  <IDENTITYPEERNAME>
    <!-- UTF-8 encoded peer name of the identity -->
  </IDENTITYPEERNAME>
  <GROUPPEERNAME>
    <!-- UTF-8 encoded peer name of the peer group -->
  </GROUPPEERNAME>
  <CLOUDNAME>
    <!-- UTF-8 encoded Unicode name of the cloud -->
  </CLOUDNAME>
  <SCOPE>
    <!-- UTF-8 encoded Unicode name of the scope: global, site-local, link-local -->
  </SCOPE>
  <CLOUDFLAGS>
    <!-- A DWORD that contains cloud-specific settings, represented as a string -->
  </CLOUDFLAGS>
  <GMC xmlns:dt="urn:schemas-microsoft-com:datatypes" dt:dt="bin.base64">
    <!-- base64/PKCS7 encoded GMC chain -->
  </GMC>
</PEERGROUPCONFIG>
```