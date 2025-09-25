# LsaStorePrivateData function

## Description

Do not use the LSA private data functions or generic data encryption and decryption. Instead, use the [CryptProtectData](https://learn.microsoft.com/windows/desktop/api/dpapi/nf-dpapi-cryptprotectdata) and [CryptUnprotectData](https://learn.microsoft.com/windows/desktop/api/dpapi/nf-dpapi-cryptunprotectdata) functions. Only use the LSA private data functions when it is necessary to manipulate LSA secrets as documented in [Secret Object Data Model](https://learn.microsoft.com/openspecs/windows_protocols/ms-lsad/483f1b6e-7b14-4341-9ab2-9b99c01f896e)

## Parameters

### `PolicyHandle` [in]

A handle to a [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object. The handle must have the POLICY_CREATE_SECRET access right if this is the first time data is being stored under the key specified by the *KeyName* parameter. For more information, see
[Opening a Policy Object Handle](https://learn.microsoft.com/windows/desktop/SecMgmt/opening-a-policy-object-handle).

### `KeyName` [in]

Pointer to an
[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure containing the name of the key under which the private data is stored.

### `PrivateData` [in]

Pointer to an [LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure containing the private data to store. The function encrypts this data before storing it.

If this parameter is **NULL**, the function deletes any private data stored under the key and deletes the key. Subsequent attempts to retrieve data from the key will return the STATUS_OBJECT_NAME_NOT_FOUND error code.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code. For more information, see
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

You can use the
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function to convert the NTSTATUS code to a Windows error code.

## Remarks

The **LsaStorePrivateData** function can be used by server applications to store client and machine passwords.

As described in
[Private Data Object](https://learn.microsoft.com/windows/desktop/SecMgmt/private-data-object), private data objects include three specialized types: local, global, and machine. Specialized objects are identified by a prefix in the key name: "L$" for local objects, "G$" for global objects, and "M$" for machine objects. Local objects cannot be accessed remotely. Machine objects can be accessed only by the operating system.

In addition to these prefixes, the following values also indicate local or machine objects. These values are supported for backward compatibility and should not be used when you create new local or machine objects. The key name of local private data objects may also be "$machine.acc", "SAC", "SAI", "SANSC", or start with "RasDialParms" or "RasCredentials". The key name for machine objects may also start with, "NL$" or "_sc_".

Private data objects which do not use any of the preceding key name conventions can be accessed remotely and are not replicated to other domains.

The data stored by the **LsaStorePrivateData** function is not absolutely protected. However, the data is encrypted before being stored, and the key has a [DACL](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) that allows only the creator and administrators to read the data.

Use the
[LsaRetrievePrivateData](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaretrieveprivatedata) function to retrieve the value stored by **LsaStorePrivateData**.

## See also

[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string)

[LsaRetrievePrivateData](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaretrieveprivatedata)