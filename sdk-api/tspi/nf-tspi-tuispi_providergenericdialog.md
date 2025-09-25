# TUISPI_providerGenericDialog function

## Description

The
**TUISPI_providerGenericDialog** function in the UI DLL is called when the service provider sends a
[LINE_CREATEDIALOGINSTANCE](https://learn.microsoft.com/windows/desktop/Tapi/line-createdialoginstance) message. The service provider uses this to create dialog boxes in the application context in conjunction with the processing of particular asynchronous TSPI functions. This function is called from a thread created specifically for the purpose of displaying the dialog box. The UI DLL does not return from this function until the dialog box is destroyed.

Implementation is mandatory if the service provider associated with the UI DLL sends LINE_CREATEDIALOGINSTANCE messages to spontaneously create dialog boxes in the application context.

## Parameters

### `lpfnUIDLLCallback`

Pointer to a function the UI DLL can call to communicate with the service provider DLL to obtain information needed to display the dialog box.

### `htDlgInst`

The opaque identifier binding the association of this instance of the function to a particular request from the service provider. The UI DLL must include this parameter, along with TUISPI_OBJECT_DIALOGINSTANCE, in any call to
[TUISPIDLLCALLBACK](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-tuispidllcallback) to request further data from or deliver data to the service provider.

### `lpParams`

Pointer to a memory area used to hold a parameter block. The contents of this parameter block are specific to the service provider and its associated UI DLL. The conveyance of data through this parameter block is one-way to the UI DLL; changes made to the parameter block are not reflected back in the service provider. Generally, this parameter block holds all information the UI DLL needs to initially display the dialog box.

### `dwSize`

The size in bytes of the parameter block. If the *lpParams* parameter is a pointer to a string, the size must include the **null** terminator.

### `hEvent`

Handle to an event object created by TAPI. This event is signaled by the UI DLL through
[SetEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-setevent) (*hEvent*) when the UI DLL has completed initialization of this dialog box instance and is prepared to receive additional dialog box data through
[TUISPI_providerGenericDialogData](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_providergenericdialogdata). Data sent by the associated service provider (through
[LINE_SENDDIALOGINSTANCEDATA](https://learn.microsoft.com/windows/desktop/Tapi/line-senddialoginstancedata)) for this dialog box instance are blocked by TAPI until the UI DLL signals this event, giving
**TUISPI_providerGenericDialog** the opportunity to perform any necessary initialization. The UI DLL should signal the event as quickly a possible to avoid blocking calls to
**TUISPI_providerGenericDialogData**.

## Return value

Returns zero if successful, or one of these negative error values:

LINEERR_INVALPARAM, LINEERR_NOMEM, LINEERR_OPERATIONFAILED.

## See also

[LINE_CREATEDIALOGINSTANCE](https://learn.microsoft.com/windows/desktop/Tapi/line-createdialoginstance)

[LINE_SENDDIALOGINSTANCEDATA](https://learn.microsoft.com/windows/desktop/Tapi/line-senddialoginstancedata)

[SetEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-setevent)

[TUISPIDLLCALLBACK](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-tuispidllcallback)

[TUISPI_providerGenericDialogData](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_providergenericdialogdata)