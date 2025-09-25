## Description

The **MmGetMdlByteOffset** macro returns the byte offset within the initial page of the buffer described by the given MDL.

## Parameters

### `Mdl` [in]

Pointer to an MDL.

## Remarks

**MmGetMdlByteOffset** returns the offset in bytes.

Callers of **MmGetMdlByteOffset** can be running at any IRQL. Usually, callers are running at IRQL <= DISPATCH_LEVEL.