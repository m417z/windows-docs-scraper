# TUISPI_providerGenericDialogData function

## Description

The
**TUISPI_providerGenericDialogData** function in the UI DLL is called when the service provider sends a
[LINE_SENDDIALOGINSTANCEDATA](https://learn.microsoft.com/windows/desktop/Tapi/line-senddialoginstancedata) message. The service provider uses this to spontaneously update information in dialog boxes created in the application context in conjunction with the processing of particular asynchronous TSPI functions. This function is called from a separate thread from that in which
**TUISPI_providerGenericDialogData** is executing. The UI DLL should not block the thread in which this function is called, but should process the data and return immediately (posting a message to the dialog box if necessary).

Implementation is mandatory if
[TUISPI_providerGenericDialog](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_providergenericdialog) is exported.

## Parameters

### `htDlgInst`

The opaque identifier binding the association of this instance of the function to a particular request from the service provider.

### `lpParams`

Pointer to a memory area used to hold a parameter block. The contents of this parameter block are specific to the service provider and its associated UI DLL. The conveyance of data through this parameter block is one-way to the UI DLL; changes made to the parameter block are not reflected back in the service provider. If this parameter is set to **NULL**, this is a request to close the dialog box immediately and clean up (
[TUISPIDLLCALLBACK](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-tuispidllcallback) should not be invoked during this cleanup). TAPI invokes this function with *lpParams* set to **NULL** to force dialog box cleanup under certain circumstances, such as an application calling
[lineShutdown](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineshutdown) with a dialog box still active.

### `dwSize`

The size in bytes of the parameter block. If the *lpParams* parameter is a pointer to a string, the size must include the **null** terminator.

## Return value

Returns zero if successful, or one of these negative error values:

LINEERR_INVALPARAM, LINEERR_NOMEM, LINEERR_OPERATIONFAILED.

## See also

[LINE_SENDDIALOGINSTANCEDATA](https://learn.microsoft.com/windows/desktop/Tapi/line-senddialoginstancedata)

[TUISPIDLLCALLBACK](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-tuispidllcallback)

[lineShutdown](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineshutdown)