# TUISPIDLLCALLBACK callback function

## Description

The *DllCallbackProc*
function is called by the UI DLL to send a private parameter block to the service provider. Each invocation of the callback results in a call to the
[TSPI_providerGenericDialogData](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providergenericdialogdata) function in the service provider associated with the specified object. The contents of the parameter block are defined by the service provider and UI DLL. The service provider can modify the contents of the parameter block; when this function returns, TAPI copies the modified data back into the original UI DLL parameter block.

The **TUISPIDLLCALLBACK** type defines a pointer to this callback function. *DllCallbackProc* is a placeholder for the application-defined function name.

## Parameters

### `dwObjectID`

An object identifier of the type specified by *dwObjectType*.

### `dwObjectType`

One of the
[TUISPIDLL_OBJECT_](https://learn.microsoft.com/windows/desktop/Tapi/tuispidll-object-) constants, specifying the type of object identified by *dwObjectID*

#### TUISPIDLL_OBJECT_LINEID

The *dwObjectID* parameter is a line device identifier (*dwDeviceID*). This is used when the callback is invoked during the processing of
[TUISPI_lineConfigDialog](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_lineconfigdialog) or
[TUISPI_lineConfigDialogEdit](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_lineconfigdialogedit).

#### TUISPIDLL_OBJECT_PHONEID

The *dwObjectID* parameter is a phone device identifier (*dwDeviceID*). This is used when the callback is invoked during the processing of
[TUISPI_phoneConfigDialog](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_phoneconfigdialog).

#### TUISPIDLL_OBJECT_PROVIDERID

The *dwObjectID* parameter is a permanent provider identifier. This is used when the callback is invoked during the processing of
[TUISPI_providerConfig](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_providerconfig),
[TUISPI_providerInstall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_providerinstall), or
[TUISPI_providerRemove](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_providerremove).

#### TUISPIDLL_OBJECT_DIALOGINSTANCE

The *dwObjectID* parameter is an HDRVDIALOGINSTANCE, as returned to the service provider when it sent a
[LINE_CREATEDIALOGINSTANCE](https://learn.microsoft.com/windows/desktop/Tapi/line-createdialoginstance) message. This is used when the callback is invoked during the processing of
[TUISPI_providerGenericDialog](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_providergenericdialog).

### `lpParams`

Pointer to a memory area used to hold a parameter block.

### `dwSize`

The size in bytes of the parameter block.

**Note** If the size parameters in the structure are not correct, there is a possibility that data could get overwritten. For more information on setting structure sizes, see the
[memory allocation](https://learn.microsoft.com/windows/desktop/Tapi/memory-allocation) topic.

## Return value

Returns zero if successful, or one of these negative error values:

LINEERR_INVALPARAM, LINEERR_INVALPOINTER, LINEERR_NOMEM, LINEERR_OPERATIONFAILED.

## See also

[LINE_CREATEDIALOGINSTANCE](https://learn.microsoft.com/windows/desktop/Tapi/line-createdialoginstance)

[TSPI_providerGenericDialogData](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providergenericdialogdata)

[TUISPIDLL_OBJECT_](https://learn.microsoft.com/windows/desktop/Tapi/tuispidll-object-)

[TUISPI_lineConfigDialog](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_lineconfigdialog)

[TUISPI_lineConfigDialogEdit](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_lineconfigdialogedit)

[TUISPI_phoneConfigDialog](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_phoneconfigdialog)

[TUISPI_providerConfig](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_providerconfig)

[TUISPI_providerGenericDialog](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_providergenericdialog)

[TUISPI_providerInstall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_providerinstall)

[TUISPI_providerRemove](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_providerremove)