# SetDotStuffState function

## Description

Enables dot stuffing to be set in an [FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10)) structure.

## Parameters

### `pContext` [in]

A pointer to the [FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10)) structure to be examined.

### `fKnown` [in]

Specifies whether the dot stuff state is known. If **TRUE**, the message requires dot stuffing and the *fRequiresStuffing* parameter becomes meaningful.

### `fRequiresStuffing` [in]

Specifies whether dot stuffing is required. If *fKnown* is **TRUE**, *fRequiresStuffing* can be either **TRUE** or **FALSE**. If *fKnown* is **FALSE**, *fRequiresStuffing* is ignored.

## See also

[FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10))