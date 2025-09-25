# CertRemoveStoreFromCollection function

## Description

The **CertRemoveStoreFromCollection** function removes a sibling [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) from a collection store.

## Parameters

### `hCollectionStore` [in]

A handle of the collection certificate store.

### `hSiblingStore` [in]

Handle of the sibling certificate store to be removed from the collection store.

## See also

[CertAddStoreToCollection](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddstoretocollection)

[CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore)

[Certificate Store Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)