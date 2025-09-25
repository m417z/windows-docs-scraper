# SCardWriteCacheA function

## Description

The **SCardWriteCache** function writes a name-value pair from a smart card to the global cache maintained by the [Smart Card Resource Manager](https://learn.microsoft.com/windows/desktop/SecAuthN/smart-card-resource-manager).

## Parameters

### `hContext` [in]

A handle that identifies the [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). The resource manager context is set by a previous call to
[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext).

### `CardIdentifier` [in]

A pointer to a value that uniquely identifies the smart card from which the name-value pair was read.

### `FreshnessCounter` [in]

The current revision of the cached data.

### `LookupName` [in]

A pointer to a null-terminated string that contains the name portion of the name-value pair to write to the global cache.

### `Data` [in]

A pointer to an array of byte values that contain the value portion of the name-value pair to write to the global cache.

### `DataLen` [in]

The size, in bytes, of the *Data* buffer.

## Return value

If the function succeeds, it returns **SCARD_S_SUCCESS**.

If the function fails, it returns one of the following error codes. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values).

| Return code/value | Description |
| --- | --- |
| **SCARD_W_CACHE_ITEM_TOO_BIG**<br><br>0x80100072 | The size of the specified name-value pair exceeds the maximum size defined for the global cache. |

## See also

[SCardReadCache](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardreadcachea)

## Remarks

> [!NOTE]
> The winscard.h header defines SCardWriteCache as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).