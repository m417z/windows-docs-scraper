# _SEARCHMEMORY structure

## Description

The **SearchMemory** function searches the target's virtual memory for a specified pattern of bytes.

## Members

### `SearchAddress`

Specifies the address in the target's virtual memory from which to start the search.

### `SearchLength`

Specifies the size, in bytes, of the memory to search. For a successful match, the pattern must be found before *SearchLength* bytes have been examined.

### `FoundAddress`

Receives the location of the pattern, found in the target's virtual memory. If the pattern was not found, the value in *FoundAddress* is unchanged by this function.

### `PatternLength`

Specifies the size, in bytes, of the pattern to search for.

### `Pattern`

Specifies the pattern to search for.