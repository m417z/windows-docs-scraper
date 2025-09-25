# SetDotStuffingOnWrites function

## Description

Enables dot-stuffing properties on the write path of the file handle cache of the message.

## Parameters

### `pContext` [in]

A pointer to an [FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10)) structure that contains context information.

### `fEnable` [in]

Specifies whether dot stuffing is available. If **FALSE**, all dot-stuffing behavior is turned off.

### `fStripDots` [in]

Specifies whether occurrences of "\r\n." are converted to "\r\n" within the message. If **TRUE**, "\r\n." is converted to "\r\n" (unstuffing or stripping). If **FALSE**, "\r\n." is converted to "\r\n.." (stuffing).

## Return value

Returns **TRUE** if the function succeeds; otherwise, it is **FALSE**.

## See also

[FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10))