# ProduceDotStuffedContext function

## Description

Retrieves the [FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10)) structure with the requested state.

## Parameters

### `pContext` [in]

A pointer to an [FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10)) structure.

### `lpstrName` [in]

Not currently used.

### `fWantItDotStuffed` [in]

Specifies whether the [FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10)) structure should be dot stuffed. If **TRUE**, dots should be added. If **FALSE**, dots should be removed.

## Return value

Returns the [FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10)) structure.

## Remarks

This call may or may not create a new [FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10)) structure. If a new structure is created, it remains in the cache so that it can be used again. If a new structure is created, the user has the only reference to the resulting [FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10)) structure, so it disappears when [ReleaseContext](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms527734(v=exchg.10)) is called.

## See also

[FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10))

[ReleaseContext](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms527734(v=exchg.10))