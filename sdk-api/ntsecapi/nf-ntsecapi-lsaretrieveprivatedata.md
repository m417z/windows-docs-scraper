# LsaRetrievePrivateData function

## Description

Do not use the LSA private data functions for generic data encryption and decryption. Instead, use the [CryptProtectData](https://learn.microsoft.com/windows/desktop/api/dpapi/nf-dpapi-cryptprotectdata) and [CryptUnprotectData](https://learn.microsoft.com/windows/desktop/api/dpapi/nf-dpapi-cryptunprotectdata) functions. Only use the LSA private data functions when it is necessary to manipulate LSA secrets as documented in [Secret Object Data Model](https://learn.microsoft.com/openspecs/windows_protocols/ms-lsad/483f1b6e-7b14-4341-9ab2-9b99c01f896e)

## Parameters

### `PolicyHandle` [in]

A handle to a [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object. The handle must have the POLICY_GET_PRIVATE_INFORMATION access right. For more information, see
[Opening a Policy Object Handle](https://learn.microsoft.com/windows/desktop/SecMgmt/opening-a-policy-object-handle).

### `KeyName` [in]

Pointer to an
[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that contains the name of the key under which the private data is stored.

To create a specialized object, add one of the following prefixes to the key name.

| Prefix | Meaning |
| --- | --- |
| **L$** | For local objects. |
| **G$** | For global objects. |
| **M$** | For computer objects. |

If you are not creating one of these specialized types, you do not need to specify a key name prefix. For more information, see
[Private Data Object](https://learn.microsoft.com/windows/desktop/SecMgmt/private-data-object).

### `PrivateData` [out]

Pointer to a variable that receives a pointer to an [LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that contains the private data.

When you no longer need the information, pass the returned pointer to
[LsaFreeMemory](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreememory).

## Return value

If the function succeeds, the function returns STATUS_SUCCESS.

If the function fails, it returns an **NTSTATUS** value, which can be the following value or one of the
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

| Return code | Description |
| --- | --- |
| **STATUS_OBJECT_NAME_NOT_FOUND** | No private data is stored under the name specified by the *KeyName* parameter. |

You can use the
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function to convert the **NTSTATUS** value to a Windows error code.

## Remarks

You must run this process "As Administrator" or the call fails with ERROR_ACCESS_DENIED.

## See also

[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string)

[LsaFreeMemory](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsafreememory)

[LsaStorePrivateData](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsastoreprivatedata)