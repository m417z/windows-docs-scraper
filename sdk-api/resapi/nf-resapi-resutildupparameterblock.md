# ResUtilDupParameterBlock function

## Description

Performs a member-wise copy of the data from one [parameter block](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/parameter-blocks) to another.

## Parameters

### `pOutParams` [out]

Pointer to the duplicated parameter block.

### `pInParams` [in]

Pointer to the original parameter block.

### `pPropertyTable` [in]

Pointer to an array of [RESUTIL_PROPERTY_ITEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resutil_property_item) structures describing properties in the original parameter block.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

**ResUtilDupParameterBlock** copies data only for parameter block members referenced in the *pPropertyTable* input parameter. If a variable in the input parameter block is a pointer, memory for the data is allocated with the function [LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc). You should deallocate this memory by calling either [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) for each pointer variable in the output parameter block or [ResUtilFreeParameterBlock](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilfreeparameterblock). Make sure that you deallocate memory whether **ResUtilDupParameterBlock** succeeds or fails. For more information, see [Using Parameter Blocks](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/using-parameter-blocks) and [Using Lists and Tables](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/using-lists-and-tables).

## See also

[RESUTIL_PROPERTY_ITEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resutil_property_item)

[ResUtilFreeParameterBlock](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilfreeparameterblock)