# CERT_SYSTEM_STORE_RELOCATE_PARA structure

## Description

The **CERT_SYSTEM_STORE_RELOCATE_PARA** structure contains data to be passed to
[CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore) when that function's *dwFlags* parameter is set to CERT_SYSTEM_STORE_RELOCATE_FLAG. It allows the application to specify not only the name of the store to be opened, but also registry hKey information indicating a registry location other than the default location.

## Members

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.hKeyBase`

A handle to registry hKey.

### `DUMMYUNIONNAME.pvBase`

A pointer to a void to allow the system store location's base to be passed in a number of different forms.

### `DUMMYUNIONNAME2`

### `DUMMYUNIONNAME2.pvSystemStore`

A pointer to a void to allow the name of the system store to be passed in various forms.

### `DUMMYUNIONNAME2.pszSystemStore`

A null-terminated [ASCII](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) string that names the system store.

### `DUMMYUNIONNAME2.pwszSystemStore`

A null-terminated Unicode string that names the system store.

## Remarks

The relocate capability is used to access system stores persisted in the Group Policy Template (GPT). For example, the Group Policy Editor's MMC snap-in extension for managing group policy trust lists and certificates uses the GPT's base HKEY to call
[CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore).

## See also

[CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore)