# GetDotStuffState function

## Description

Determines whether dots are added to the file when any dot stuffing mechanisms are turned on.

## Parameters

### `pContext` [in]

A pointer to the [FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10)) structure.

### `fReads` [in]

Indicates the dot stuff states that resulted from reads or from writes. If **TRUE**, the states of Reads are provided. If **FALSE**, the states of Writes are provided.

### `pfStuffed` [out]

Indicates whether any dots were processed, scanned, or modified. If no dots were processed, scanned, or modified, this value is **FALSE**; otherwise, it is **TRUE**.

**Note** This parameter cannot be set to **NULL**.

### `pfStoredWithDots` [out]

Indicates whether the file was stored with stuffed dots.

## Return value

Returns **TRUE** if the dot stuff state is known; otherwise, it returns **FALSE**.

## Remarks

The information about dot stuffing is provided by DOT_STUFF_MANAGER objects.

## See also

[FIO_CONTEXT](https://learn.microsoft.com/previous-versions/exchange-server/exchange-10/ms528326(v=exchg.10))