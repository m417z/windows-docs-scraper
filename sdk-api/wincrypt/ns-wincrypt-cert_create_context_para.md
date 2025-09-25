# CERT_CREATE_CONTEXT_PARA structure

## Description

The **CERT_CREATE_CONTEXT_PARA** structure defines additional values that can be used when calling the [CertCreateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcreatecontext) function.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `pfnFree`

A pointer to the function that frees the *pbEncoded* parameter of the [CertCreateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcreatecontext) function. The **pfnFree** function is called when the context created by **CertCreateContext** is freed. This value can be **NULL**, in which case the *pbEncoded* parameter of the **CertCreateContext** function is not freed.

### `pvFree`

The address of the memory that gets freed by the **pfnFree** function. If **pvFree** is **NULL**, then the *pbEncoded* parameter of the [CertCreateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcreatecontext) function is freed.

### `pfnSort`

A [PFN_CERT_CREATE_CONTEXT_SORT_FUNC](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_create_context_sort_func) function pointer that will be called for each sorted context entry.

This member is only present for a **CERT_STORE_CTL_CONTEXT** when the **CERT_CREATE_CONTEXT_SORTED_FLAG** flag is set in the *dwFlags* parameter of the [CertCreateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcreatecontext) function. You must verify that this member is present before trying to access it by examining the **cbSize** member of this structure.

### `pvSort`

An application-defined value that will be passed in the *pvSort* parameter of the [PFN_CERT_CREATE_CONTEXT_SORT_FUNC](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_create_context_sort_func) callback function.

This member is only present for a **CERT_STORE_CTL_CONTEXT** when the **CERT_CREATE_CONTEXT_SORTED_FLAG** flag is set in the *dwFlags* parameter of the [CertCreateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcreatecontext) function. You must verify that this member is present before trying to access it by examining the **cbSize** member of this structure.

## See also

[CertCreateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcreatecontext)

[PFN_CERT_CREATE_CONTEXT_SORT_FUNC](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_create_context_sort_func)