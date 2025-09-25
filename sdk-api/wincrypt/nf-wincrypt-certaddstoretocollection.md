# CertAddStoreToCollection function

## Description

The **CertAddStoreToCollection** function adds a sibling [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to a collection certificate store. When a certificate store has been added to a collection store, all of the certificates, [certificate revocation lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRLs), and [certificate trust lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTLs) in the store that has been added to the collection store can be retrieved by using find or enumerate function calls that use the collection store.

## Parameters

### `hCollectionStore` [in]

Handle of a certificate store.

### `hSiblingStore` [in, optional]

Handle of a sibling store to be added to the collection store. For more information, see Remarks.

### `dwUpdateFlags` [in]

Indicates whether [certificates](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), CRLs, and CTLs can be added to the new sibling store member of the collection store. To enable addition, set *dwUpdateFlag* to CERT_PHYSICAL_STORE_ADD_ENABLE_FLAG. To disable additions, set *dwUpdateFlag* to zero.

### `dwPriority` [in]

Sets a priority level of the new store in the collection, with zero being the lowest priority. If zero is passed for this parameter, the specified store is appended as the last store in the collection. The priority levels of the stores in a collection determine the order in which the stores are enumerated, and the search order of the stores when attempting to retrieve a certificate, CRL, or CTL. Priority levels also determine to which store of a collection a new certificate, CRL, or CTL is added. For more information, see Remarks.

## Return value

If the function succeeds, the function returns nonzero and a new store is added to the collection of stores.

If the function fails, it returns zero and the store was not added.

## Remarks

A collection store has the same **HCERTSTORE** handle as a single store; thus, almost all functions that apply to any [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) also apply to any collection store. Enumeration and search processes span all of the stores in a collection store; however, functions such as
[CertAddCertificateLinkToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddcertificatelinktostore) that add links to stores cannot be used with collection stores.

When a certificate, CRL, or CTL is added to a collection store, the list of sibling stores in the collection is searched in priority order to find the first store that allows adding. Adding is enabled if CERT_PHYSICAL_STORE_ADD_ENABLE_FLAG was set in the **CertAddStoreToCollection** call. With any function that adds elements to a store, if a store that allows adding does not return success, the addition function continues on to the next store without providing notification.

When a collection store and its sibling stores are closed with
[CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore) using CERT_CLOSE_STORE_FORCE_FLAG, the collection store must be closed before its sibling stores. If CERT_CLOSE_STORE_FORCE_FLAG is not used, the stores can be closed in any order.

#### Examples

The following example shows adding a sibling certificate store to a collection certificate store. For a full example including the complete context for this example, see
[Example C Program: Collection and Sibling Certificate Store Operations](https://learn.microsoft.com/windows/desktop/SecCrypto/example-c-program-collection-and-sibling-certificate-store-operations).

```cpp
//-------------------------------------------------------------------
// Declare and initialize variables.

HCERTSTORE  hCollectionStore = NULL;     // The collection store
                                         // handle
HCERTSTORE  hMemoryStore = NULL;         // A memory store handle
LPCSTR pszFileName = "TestStor.sto";     // Output file name
LPWSTR pswzFirstCert = L"Full Test Cert";// Subject of the first
                                         // certificate
LPWSTR pswzSecondCert = L"Microsoft";    // Subject of the second
                                         // certificate
//-------------------------------------------------------------------
// Open a collection certificate store.

if(hCollectionStore = CertOpenStore(
    CERT_STORE_PROV_COLLECTION, // A collection store
    0,                          // Encoding type; not used with a
                                // collection store
    NULL,                       // Use the default provider
    0,                          // No flags
    NULL))                      // Not needed

{
    printf("The collection store was opened. \n");
}
else
{
    printf( "There was an error while opening the "
        "collection store! \n");
    exit(1);
}
//-------------------------------------------------------------------
// Open a new certificate store in memory.

if(hMemoryStore = CertOpenStore(
    CERT_STORE_PROV_MEMORY,    // A memory store
    0,                         // Encoding type; not used with a
                               // memory store
    NULL,                      // Use the default provider
    0,                         // No flags
    NULL))                     // Not needed
{
    printf("The memory store was opened. \n");
}
else
{
    printf( "There was an error while opening the memory store! \n");
    exit(1);
}
//-------------------------------------------------------------------
// Add the memory store as a sibling to the collection store.
// All certificates in the memory store and any new certificate
// added to the memory store will also be available in the
// collection
// store.

if(CertAddStoreToCollection(
    hCollectionStore,
    hMemoryStore,
    CERT_PHYSICAL_STORE_ADD_ENABLE_FLAG,  // New certificates can be
                                          // added to the sibling
                                          // store.
    1))                                   // The sibling store's
                                          // priority.
                                          // Because this is the
                                          // store with the highest
                                          // priority, certificates
                                          // added to the collection
                                          // store will actually be
                                          // stored in this store.
{
    printf("The memory store was added to the collection store.\n");
}
else
{
    printf("The memory store was not added to the "
        "collection store.\n");
    exit(1);
}

//-------------------------------------------------------------------
// The store handles must be closed.

if(CertCloseStore(hCollectionStore,
                  0))
{
    printf("The collection store was closed. \n");
}
else
{
    printf("There was an error while closing the "
        "collection store! \n");
}

if(CertCloseStore(hMemoryStore, 0))
{
    printf("The memory store was closed. \n");
}
else
{
    printf("There was an error while closing the memory store! \n");
}

```

## See also

[CertRemoveStoreFromCollection](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certremovestorefromcollection)

[Certificate Store Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)