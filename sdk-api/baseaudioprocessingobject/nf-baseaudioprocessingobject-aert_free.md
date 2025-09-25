# AERT_Free function

## Description

The `AERT_Free` utility function releases (frees) memory that was locked by the [AERT_Allocate](https://learn.microsoft.com/windows/desktop/api/baseaudioprocessingobject/nf-baseaudioprocessingobject-aert_allocate) function, for use by audio processing objects to process audio data.

## Parameters

### `pMemory`

A pointer to the memory that the `AERT_Free` function will free.

## Return value

The `AERT_Free` function returns a value of S_OK after it frees the locked memory.

## Remarks

None

## See also

[AERT_Allocate](https://learn.microsoft.com/windows/desktop/api/baseaudioprocessingobject/nf-baseaudioprocessingobject-aert_allocate)