# TUISPICREATEDIALOGINSTANCEPARAMS structure

## Description

Defines parameters for TAPI dialog operations.

## Members

### `dwRequestID`

The **dwRequestID** passed to the service provider as a parameter in the asynchronous TSPI function with which the spontaneous UI is associated. TAPI uses this to identify the application in whose context the UI DLL is to be loaded and the
[TUISPI_providerGenericDialog](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_providergenericdialog) function invoked.

### `hdDlgInst`

The service provider's identifier for the association with the instance of the generic dialog box. Because it is possible for multiple instances of the generic dialog box to be open in the same or multiple applications, the service provider must ensure that its handle is unique within the scope of existing instances within the context of the provider.

### `htDlgInst`

TAPI writes into this member its identifier for the association that is created. This member is set to **NULL** if creating the association failed, in which case it is impossible for the service provider to create a dialog box spontaneously in the context of the target application. The service provider must use this identifier in messages to send data to the UI DLL ([LINE_SENDDIALOGINSTANCEDATA](https://learn.microsoft.com/windows/desktop/Tapi/line-senddialoginstancedata)).

### `lpszUIDLLName`

Pointer to a **NULL**-terminated string specifying the fully qualified name of the UI DLL to load in the application context.

### `lpParams`

Pointer to a private parameter block to be conveyed to the UI DLL's
[TUISPI_providerGenericDialog](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_providergenericdialog) function. The service provider and UI DLL determine the contents of the parameter block. The transfer is unidirectional; the UI DLL is not able to modify the parameter block and return it to the service provider. Generally, this block instructs the UI DLL which dialog box to display, and contains the information to display (if necessary).

### `dwSize`

The size, in bytes, of the parameter block.

## See also

[LINE_SENDDIALOGINSTANCEDATA](https://learn.microsoft.com/windows/desktop/Tapi/line-senddialoginstancedata)

[TUISPI_providerGenericDialog](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_providergenericdialog)