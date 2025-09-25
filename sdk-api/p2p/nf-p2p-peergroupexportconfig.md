# PeerGroupExportConfig function

## Description

The **PeerGroupExportConfig** function exports the group configuration for a peer as an XML string that contains the identity, group name, and the GMC for the identity.

## Parameters

### `hGroup` [in]

Handle to the group. This handle is returned by the [PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate), [PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen), or [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) function. This parameter is required.

### `pwzPassword` [in]

Specifies the password used to protect the exported configuration. There are no rules or limits for the formation of this password. This parameter is required.

### `ppwzXML` [out]

Pointer to the returned XML configuration string that contains the identity, group peer name, cloud peer name, group scope, and the GMC for the identity. This parameter is required.

## Return value

Returns **S_OK** if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |
| **PEER_E_NO_KEY_ACCESS** | Access to the identity or group keys is denied. Typically, this is caused by an incorrect access control list (ACL) for the folder that contains the user or computer keys. This can happen when the ACL is reset manually . |

Cryptography-specific errors can be returned from the [Microsoft Base Cryptographic Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## Remarks

After being exported, this configuration can be passed out-of-band to another peer, where the configuration of the identity can be established. To import the configuration, pass the XML string returned by this function with the password set on it to [PeerGroupImportConfig](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupimportconfig).

The configuration XML string appears in the following format:

``` syntax
<PEERGROUPCONFIG VERSION="1.0">
  <IDENTITYPEERNAME>
    <!-- UTF-8 encoded peer name of the identity -->
  </IDENTITYPEERNAME>
  <GROUPPEERNAME>
    <!-- UTF-8 encoded peer name of the group -->
  </GROUPPEERNAME>
  <CLOUDNAME>
    <!-- UTF-8 encoded Unicode name of the cloud -->
  </CLOUDNAME>
  <SCOPE>
    <!-- UTF-8 encoded Unicode name of the scope: global, site-local, link-local -->
  </SCOPE>
  <CLOUDFLAGS>
    <!-- A DWORD containing cloud-specific settings, represented as a string -->
  </CLOUDFLAGS>
  <GMC xmlns:dt="urn:schemas-microsoft-com:datatypes" dt:dt="bin.base64">
    <!-- base64/PKCS7 encoded GMC chain -->
  </GMC>
</PEERGROUPCONFIG>
```