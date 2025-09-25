# ICertAdmin2::GetMyRoles

## Description

The **GetMyRoles** method retrieves the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) roles of the caller.

## Parameters

### `strConfig` [in]

String value that represents a valid configuration string for the CA in the form COMPUTERNAME\CANAME, where COMPUTERNAME is the Certificate Services server's network name, and CANAME is the common name of the CA, as entered during Certificate Services setup. For information about the configuration string name, see
[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig).

**Important** **GetMyRoles** does not clear the internal cache when the configuration string is changed. When you change the configuration string for the CA, you must instantiate a new [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2) object and call this method again with the new configuration string.

### `pRoles` [out]

A pointer to a **LONG** value that represents the retrieved CA roles for the caller. This can be a bitwise combination of zero or more of the following values.

| Value | Meaning |
| --- | --- |
| **CA_ACCESS_ADMIN**<br><br>0x1 | Caller has CA administrator capability. |
| **CA_ACCESS_AUDITOR**<br><br>0x4 | Caller has CA auditor capability. |
| **CA_ACCESS_ENROLL**<br><br>0x200 | Caller has enrollment access. |
| **CA_ACCESS_OFFICER**<br><br>0x2 | Caller has CA officer capability. |
| **CA_ACCESS_OPERATOR**<br><br>0x8 | Caller has CA backup capability. |
| **CA_ACCESS_READ**<br><br>0x100 | Caller has CA read access. |

## Return value

### C++

If the function is successful, the return value is S_OK.

If the function fails, the return value is an **HRESULT** that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is a **Long** value that represents the retrieved CA roles for the caller. This can be a bitwise combination of zero or more of the following values.

| Return code/value | Description |
| --- | --- |
| **CA_ACCESS_ADMIN**<br><br>0x1 | Caller has CA administrator capability. |
| **CA_ACCESS_AUDITOR**<br><br>0x4 | Caller has CA auditor capability. |
| **CA_ACCESS_ENROLL**<br><br>0x200 | Caller has enrollment access. |
| **CA_ACCESS_OFFICER**<br><br>0x2 | Caller has CA officer capability. |
| **CA_ACCESS_OPERATOR**<br><br>0x8 | Caller has CA backup capability. |
| **CA_ACCESS_READ**<br><br>0x100 | Caller has read access. |

## See also

[ICertAdmin2](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2)