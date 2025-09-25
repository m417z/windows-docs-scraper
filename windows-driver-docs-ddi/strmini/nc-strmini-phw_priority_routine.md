# PHW_PRIORITY_ROUTINE callback function

## Description

*StrMiniPriorityRoutine* is a minidriver-supplied callback routine to be executed at a specified priority level.

## Parameters

### `Context` [in]

Pointer to a minidriver-allocated buffer. The minidriver provides a pointer to this buffer in the Context parameter of its call to [StreamClassCallAtNewPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclasscallatnewpriority).

## Remarks

The minidriver provides a pointer to this routine in the **Priority** parameter of a call to [StreamClassCallAtNewPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclasscallatnewpriority).

## See also

[StreamClassCallAtNewPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclasscallatnewpriority)