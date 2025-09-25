# PFNBTH_FREE_BRB callback function

## Description

The
*BthFreeBrb* function frees a Bluetooth request block (BRB) that was allocated previously with
*BthAllocateBrb*.

## Parameters

### `pBrb` [in]

Pointer to the BRB to free.

## Remarks

Profile drivers obtain a pointer to the
*BthFreeBrb* function when they query the Bluetooth driver stack for an instance of the
BTHDDI_PROFILE_DRIVER_INTERFACE driver interface. See
[Querying for Bluetooth
Interfaces](https://learn.microsoft.com/previous-versions/ff536769(v=vs.85)) for more information about querying the Bluetooth driver stack.