# FindSyncContextFromName function

## Description

Retrieves the [FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10)) structure that is associated with the specified user name.

## Parameters

### `pNameCache` [in]

A pointer to the name cache that the client is to use.

### `lpbName` [in]

A pointer to the name of the cached item.

### `cbName` [in]

The size, in bytes, of the value in *lpbName*.

### `pfnCallback` [in]

A pointer to a [FCACHE_READ_CALLBACK](https://learn.microsoft.com/previous-versions/bb432262(v=vs.85)) function.

**Note** If this parameter is **NULL**, no callback function is called.

### `lpvClientContext` [in]

A pointer to the context that is associated with the client. This context is passed to the callback function.

### `hToken` [in]

Request the cache to evaluate the embedded security descriptor. If *hToken* is zero, it is ignored.

### `accessMask` [in]

The security descriptor data. For more information, see [ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask).

### `ppContext` [out]

A pointer to a pointer to the [FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10)) structure that is associated with the user name.

If the function returns **TRUE**, this parameter can return a **NULL** pointer. This occurs when the user passes a **NULL** FIO_CONTEXT to [_AssociateContextWithName](https://learn.microsoft.com/windows/desktop/api/filehc/nf-filehc-associatecontextwithname).

## Return value

Returns **TRUE** if the name is found in the cache; otherwise, it returns **FALSE**.

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask)

[AssociateContextWithName](https://learn.microsoft.com/windows/desktop/api/filehc/nf-filehc-associatecontextwithname)

[FCACHE_READ_CALLBACK](https://learn.microsoft.com/previous-versions/bb432262(v=vs.85))

[FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10))