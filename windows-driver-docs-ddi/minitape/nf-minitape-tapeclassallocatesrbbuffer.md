# TapeClassAllocateSrbBuffer function

## Description

The **TapeClassAllocateSrbBuffer** routine allocates an **Srb->DataBuffer**.

## Parameters

### `Srb` [in, out]

Pointer to the SRB.

### `SrbBufferSize` [in]

Specifies the size, in bytes, of the **DataBuffer** to be allocated.

## Return value

**TapeClassAllocateSrbBuffer** returns **TRUE** if the **DataBuffer** was allocated successfully, and **FALSE** if the buffer was not allocated.

## Remarks

**TapeClassAllocateSrbBuffer** allocates an **Srb->DataBuffer** from nonpaged memory and initializes the members to zero. If the buffer already exists from an earlier call, it is freed and a new buffer allocated. A tape miniclass driver calls this routine to allocate a **DataBuffer** in a portable way.