# CryptCATStoreFromHandle function

## Description

[The **CryptCATStoreFromHandle** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The [CRYPTCATSTORE](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-cryptcatstore) structure from a catalog handle.

## Parameters

### `hCatalog` [in]

A handle to the catalog obtained from the [CryptCATOpen](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatopen) or [CryptCATHandleFromStore](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcathandlefromstore) function.

## Return value

A pointer to a [CRYPTCATSTORE](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-cryptcatstore) structure that contains the catalog store. The caller must not free this pointer or any of its members.