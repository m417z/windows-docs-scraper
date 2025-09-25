# MI_Application_NewDestinationOptions function

## Description

Creates an [MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions) object that can be used with the [MI_Application_NewSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newsession) function.

## Parameters

### `application` [in]

Handle returned from [MI_Application_Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_initializev1).

### `options` [out]

Options container that is returned from this function.

## Return value

This function returns MI_INLINE MI_Result.

## Remarks

Destination options are used to store the configuration associated with connecting to the destination computer. The available options can vary depending on the underlying protocol. If the session and operations on that session just need to work with the current thread identity (or process if thread is not impersonating), then additional settings may not be needed.

Options must be closed by a call to [MI_DestinationOptions_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_destinationoptions_delete).