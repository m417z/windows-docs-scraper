# PFN_CERT_CREATE_CONTEXT_SORT_FUNC callback function

## Description

The **PFN_CERT_CREATE_CONTEXT_SORT_FUNC** callback function is called for each sorted context entry when a context is created. This function pointer is passed in the **pfnSort** member of the [CERT_CREATE_CONTEXT_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_create_context_para) structure.

## Parameters

### `cbTotalEncoded` [in]

The total number of bytes of the encoded entries.

### `cbRemainEncoded` [in]

The number of bytes remaining to be encoded.

### `cEntry` [in]

The current number of sorted entries.

### `pvSort` [in, out]

An application-defined value that is passed in the **pvSort** member of the [CERT_CREATE_CONTEXT_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_create_context_para) structure.

## Return value

Return **TRUE** to continue the sort or **FALSE** to stop the sort. If **FALSE** is returned, [CertCreateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcreatecontext) will fail and set the last error code to **ERROR_CANCELLED**.

## See also

[CERT_CREATE_CONTEXT_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_create_context_para)

[CertCreateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcreatecontext)