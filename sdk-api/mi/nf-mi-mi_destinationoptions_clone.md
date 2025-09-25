# MI_DestinationOptions_Clone function

## Description

Creates a copy of a [MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions) structure.

## Parameters

### `self` [in]

[MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions) structure to be cloned.

### `newDestinationOptions` [out]

A pointer to the returned [MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions) clone. The cloned copy must be closed with the [MI_DestinationOptions_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_destinationoptions_delete) function.

## Return value

This function returns MI_INLINE MI_Result MI_INLINE_CALL.