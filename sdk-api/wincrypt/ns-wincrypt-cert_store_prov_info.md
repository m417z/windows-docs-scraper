# CERT_STORE_PROV_INFO structure

## Description

The **CERT_STORE_PROV_INFO** structure contains information returned by the installed
[CertDllOpenStoreProv](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_dll_open_store_prov_func) function when a store is opened by using the
[CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore) function.

When opening a store, the [CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore) function sets all fields in the **CERT_STORE_PROV_INFO** structure to zero except **cbSize**, which is set to the size of **CERT_STORE_PROV_INFO**. The structure is updated by the [CertDllOpenStoreProv](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_dll_open_store_prov_func) installable function. If there are no additional callback functions to be called, then **cStoreProvFunc** remains zero upon return.

## Members

### `cbSize`

Contains the size, in bytes, of this structure.

### `cStoreProvFunc`

Contains the number of elements in the **rgpvStoreProvFunc** array. This count must include any **NULL** values that are used in indexes prior to the last callback function implemented. For example, if only one callback function is implemented, but it is at index 2 (**CERT_STORE_PROV_WRITE_CERT_FUNC**), with **NULL** for indexes 0 and 1, then the number 3 should be passed for this parameter.

### `rgpvStoreProvFunc`

An array of pointers to the callback functions that are implemented by the provider. This array is indexed by the values given in the following table, and they must be in the order shown. The associated callback function is shown as well. All callback functions that are not implemented must be set to **NULL**. The array does not have to contain all callback function indexes, it only needs to contain the highest callback function index implemented. For example, if only the **CERT_STORE_PROV_WRITE_CERT_FUNC** (2) callback function is implemented, the array only needs to contain three elements.

| Value | Meaning |
| --- | --- |
| **CERT_STORE_PROV_CLOSE_FUNC**<br><br>0 (0x0) | [CertStoreProvCloseCallback](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_store_prov_close) |
| **CERT_STORE_PROV_READ_CERT_FUNC**<br><br>1 (0x1) | [CertStoreProvReadCertCallback](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_store_prov_read_cert) |
| **CERT_STORE_PROV_WRITE_CERT_FUNC**<br><br>2 (0x2) | [CertStoreProvWriteCertCallback](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_store_prov_write_cert) |
| **CERT_STORE_PROV_DELETE_CERT_FUNC**<br><br>3 (0x3) | [CertStoreProvDeleteCertCallback](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_store_prov_delete_cert) |
| **CERT_STORE_PROV_SET_CERT_PROPERTY_FUNC**<br><br>4 (0x4) | [CertStoreProvSetCertPropertyCallback](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_store_prov_set_cert_property) |
| **CERT_STORE_PROV_READ_CRL_FUNC**<br><br>5 (0x5) | [CertStoreProvReadCRLCallback](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_store_prov_read_crl) |
| **CERT_STORE_PROV_WRITE_CRL_FUNC**<br><br>6 (0x6) | [CertStoreProvWriteCRLCallback](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_store_prov_write_crl) |
| **CERT_STORE_PROV_DELETE_CRL_FUNC**<br><br>7 (0x7) | [CertStoreProvDeleteCRLCallback](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_store_prov_delete_crl) |
| **CERT_STORE_PROV_SET_CRL_PROPERTY_FUNC**<br><br>8 (0x8) | [CertStoreProvSetCRLPropertyCallback](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_store_prov_set_crl_property) |
| **CERT_STORE_PROV_READ_CTL_FUNC**<br><br>9 (0x9) | [CertStoreProvReadCTL](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_store_prov_read_ctl) |
| **CERT_STORE_PROV_WRITE_CTL_FUNC**<br><br>10 (0xA) | [CertStoreProvWriteCTL](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_store_prov_write_ctl) |
| **CERT_STORE_PROV_DELETE_CTL_FUNC**<br><br>11 (0xB) | [CertStoreProvDeleteCTL](https://learn.microsoft.com/windows/desktop/SecCrypto/certstoreprovdeletectl) |
| **CERT_STORE_PROV_SET_CTL_PROPERTY_FUNC**<br><br>12 (0xC) | [CertStoreProvSetCTLProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_store_prov_set_ctl_property) |
| **CERT_STORE_PROV_CONTROL_FUNC**<br><br>13 (0xD) | [CertStoreProvControl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_store_prov_control) |
| **CERT_STORE_PROV_FIND_CERT_FUNC**<br><br>14 (0xE) | [CertStoreProvFindCert](https://learn.microsoft.com/windows/desktop/SecCrypto/certstoreprovfindcert) |
| **CERT_STORE_PROV_FREE_FIND_CERT_FUNC**<br><br>15 (0xF) | [CertStoreProvFreeFindCert](https://learn.microsoft.com/windows/desktop/SecCrypto/certstoreprovfreefindcert) |
| **CERT_STORE_PROV_GET_CERT_PROPERTY_FUNC**<br><br>16 (0x10) | [CertStoreProvGetCertProperty](https://learn.microsoft.com/windows/desktop/SecCrypto/certstoreprovgetcertproperty) |
| **CERT_STORE_PROV_FIND_CRL_FUNC**<br><br>17 (0x11) | [CertStoreProvFindCRL](https://learn.microsoft.com/windows/desktop/SecCrypto/certstoreprovfindcrl) |
| **CERT_STORE_PROV_FREE_FIND_CRL_FUNC**<br><br>18 (0x12) | [CertStoreProvFreeFindCRL](https://learn.microsoft.com/windows/desktop/SecCrypto/certstoreprovfreefindcrl) |
| **CERT_STORE_PROV_GET_CRL_PROPERTY_FUNC**<br><br>19 (0x13) | [CertStoreProvGetCRLProperty](https://learn.microsoft.com/windows/desktop/SecCrypto/certstoreprovgetcrlproperty) |
| **CERT_STORE_PROV_FIND_CTL_FUNC**<br><br>20 (0x14) | [CertStoreProvFindCTL](https://learn.microsoft.com/windows/desktop/SecCrypto/certstoreprovfindctl) |
| **CERT_STORE_PROV_FREE_FIND_CTL_FUNC**<br><br>21 (0x15) | [CertStoreProvFreeFindCTL](https://learn.microsoft.com/windows/desktop/SecCrypto/certstoreprovfreefindctl) |
| **CERT_STORE_PROV_GET_CTL_PROPERTY_FUNC**<br><br>22 (0x16) | [CertStoreProvGetCTLProperty](https://learn.microsoft.com/windows/desktop/SecCrypto/certstoreprovgetctlproperty) |

### `hStoreProv`

A 32-bit, application-defined value that is the first parameter passed to all callbacks. An application can specify the contents of this member as desired. Typically, this is a pointer to data that is specific to the application, such as provider state information for each store opened.

### `dwStoreProvFlags`

Contains a set of flags that specify how the provider works. Contains zero or a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_STORE_PROV_EXTERNAL_FLAG**<br><br>1 (0x1) | The provider stores [certificates](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), [certificate revocation lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), and [certificate trust lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) that are external to the store's cache. |
| **CERT_STORE_PROV_DELETED_FLAG**<br><br>2 (0x2) | The store was successfully deleted. The [CertStoreProvCloseCallback](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_store_prov_close) callback is not called. |
| **CERT_STORE_PROV_NO_PERSIST_FLAG**<br><br>4 (0x4) | By default, the provider will persist changes that are made to the store. If this flag is set, the provider does not persist the changes made to the store. |
| **CERT_STORE_PROV_SYSTEM_STORE_FLAG**<br><br>8 (0x8) | The provider persists contexts to a system store. |
| **CERT_STORE_PROV_LM_SYSTEM_STORE_FLAG**<br><br>16 (0x10) | The provider persists contexts to a LocalMachine system store. |

### `hStoreProvFuncAddr2`

Contains the handle returned by
[CryptGetOIDFunctionAddress](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetoidfunctionaddress).
[CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore) calls
[CryptFreeOIDFunctionAddress](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptfreeoidfunctionaddress) to free a non-null **hStoreProvFuncAddr2**. This allows the callback to call one other installable function that will be freed when the store is closed.