# CertSetStoreProperty function

## Description

The **CertSetStoreProperty** function sets a store property.

## Parameters

### `hCertStore` [in]

Handle for the [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

### `dwPropId` [in]

Indicates one of a range of store properties. Values for user-defined properties must be outside the current range of predefined context property values. Currently, user-defined *dwPropId* values begin at 4,096. There is one predefined store property, CERT_STORE_LOCALIZED_NAME_PROP_ID, the localized name of the store.

### `dwFlags` [in]

Reserved for future use and must be zero.

### `pvData` [in]

The type definition for *pvData* depends on the *dwPropId* value. If *dwPropId* is CERT_STORE_LOCALIZED_NAME_PROP_ID, *pvData* points to a
[CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure. The **pbData** member of that structure is a pointer to a **null**-terminated Unicode character string. The **cbData** member of that structure is a **DWORD** value holding the length of the string.

For user-defined *dwPropId* values, *pvData* is a pointer to an encoded [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)).

If a value already exists for the selected property, the old value is replaced.

Calling this function with *pvData* set to **NULL** deletes a property.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**.

## Remarks

Store property identifiers are properties applicable to an entire store. They are not properties for an individual [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), [CRL](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), or [CTL](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) context. Currently, no store properties are persisted.

#### Examples

The following example shows setting the localized name property of an open certificate store.

```cpp
//--------------------------------------------------------------
// Declare and initialize variables.

HCERTSTORE hCertStore = NULL;       // Original certificate store
CRYPT_DATA_BLOB Property_Name_Blob; // BLOB to hold store property

//--------------------------------------------------------------
// Open the certificate store that will have its localized name
// property set. In this case, the CA system store is opened.

if ( hCertStore = CertOpenStore(
    CERT_STORE_PROV_SYSTEM,
    0,
    NULL,
    CERT_SYSTEM_STORE_CURRENT_USER,
    L"CA"))
{
     printf("The CA store is open.\n");
}
else
{
     printf("The CA store could not be opened \n.");
     exit(1);
}

//--------------------------------------------------------------------
// Prepare a data structure to set a store property.
// Initialize the members of the CRYPT_DATA_BLOB.
Property_Name_Blob.pbData = (BYTE *) L"The Local CA Store";
Property_Name_Blob.cbData =
       (wcslen((LPWSTR)Property_Name_Blob.pbData)+1) * sizeof(WCHAR);

//--------------------------------------------------------------------
// Set the store's localized name property.
if (CertSetStoreProperty(
    hCertStore,
    CERT_STORE_LOCALIZED_NAME_PROP_ID,
    0,
    &Property_Name_Blob))
{
     printf("The name of the store has been set. Continue. \n");
}
else
{
     printf("Setting the store's localized name failed.\n");
     exit(1);
}

// Close the store when done.
if (!CertCloseStore(
     hCertStore,
     0 ))
{
     printf("The CA store could not be closed \n.");
     exit(1);

}
```

For another example that uses this function, see [Example C Program: Setting and Getting Certificate Store Properties](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-setting-and-getting-certificate-store-properties).

## See also

[CertGetStoreProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetstoreproperty)

[Certificate Store Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)