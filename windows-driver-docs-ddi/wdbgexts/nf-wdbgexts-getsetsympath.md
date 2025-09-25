# GetSetSympath function

## Description

The **GetSetSympath** function can be used to either get or set the symbol search path.

## Parameters

### `Arg` [in]

Specifies the new search path. If this argument is **NULL** or the string is empty, the search path is not set and the current setting is returned in *Result*.

### `Result` [out]

Optional. If *Arg* is **NULL**, **GetSetSympath** stores the current search path in the buffer pointed to by *Result*.

### `Length` [in]

Specifies the size of the buffer for storing the result.

## Remarks

When the symbol path is changed, a call to **ReloadSymbols** is made implicitly.

### Returns

None