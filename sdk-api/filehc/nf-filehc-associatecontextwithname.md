# AssociateContextWithName function

## Description

Inserts a name into the name cache to find a specified [FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10)) structure.

## Parameters

### `pNameCache` [in]

A pointer to the name of the cache to be used.

### `lpbName` [in]

User-specified bytes for the name of the cache item.

### `cbName` [in]

The length of the name that is assigned to the cache item.

### `lpbData` [in]

User-specified bytes for any arbitrary data to associate with the name of the cache item.

### `cbData` [in]

The length, in bytes, of arbitrary data to associate with the name.

### `pGenericMapping` [in]

A pointer to a [GENERIC_MAPPING](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-generic_mapping) structure to associate with the name.

### `pSecurityDescriptor` [in]

The self-relative security descriptor to be associated with the name. This descriptor is provided by the user.

### `pContext` [in]

A pointer to an [FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10)) structure.

### `fKeepReference` [in]

Specifies whether the reference on the [FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10)) structure should be kept. If set to **TRUE**, the reference is kept.

## Return value

Returns **TRUE** if the function succeeds; otherwise, it returns **FALSE**.

## Remarks

If the name is already present in the cache, this call fails and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_DUP_NAME.

## See also

[FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10))

[GENERIC_MAPPING](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-generic_mapping)