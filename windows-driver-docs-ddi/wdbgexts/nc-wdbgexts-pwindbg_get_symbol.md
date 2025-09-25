# PWINDBG_GET_SYMBOL callback function

## Description

The **PWINDBG_GET_SYMBOL** (**GetSymbol**) function locates the symbol nearest to *address*.

## Parameters

### `offset`

Specifies an address near the symbol you want located.

### `pchBuffer`

Receives the name of the symbol found. This buffer must be at least 256 characters in length.

### `pDisplacement`

Specifies the displacement from the beginning of the symbol.