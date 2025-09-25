# TSPI_providerGenericDialogData function

## Description

The
**TSPI_providerGenericDialogData** function delivers to the service provider data that was sent from the UI DLL running in an application context through the
[TUISPIDLLCALLBACK](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-tuispidllcallback) function. The contents of the memory block pointed to by *lpParams* is defined by the service provider and UI DLL. The service provider can modify the contents of the parameter block; when this function returns, TAPI copies the modified data back into the original UI DLL parameter block.

Implementation is mandatory if the UI DLL associated with the service provider calls
[TUISPIDLLCALLBACK](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-tuispidllcallback).

## Parameters

### `dwObjectID`

An object identifier of the type specified by *dwObjectType*.

### `dwObjectType`

One of the
[TUISPIDLL_OBJECT_](https://learn.microsoft.com/windows/desktop/Tapi/tuispidll-object-) constants, specifying the type of object identified by *dwObjectID*:

#### TUISPIDLL_OBJECT_LINEID

*dwObjectID* is a line device identifier (dwDeviceID).

#### TUISPIDLL_OBJECT_PHONEID

*dwObjectID* is a phone device identifier (dwDeviceID)

#### TUISPIDLL_OBJECT_PROVIDERID

*dwObjectID* is a permanent provider identifier.

#### TUISPIDLL_OBJECT_DIALOGINSTANCE

*dwObjectID* is an HDRVDIALOGINSTANCE, as returned to the service provider when it sent a
[LINE_CREATEDIALOGINSTANCE](https://learn.microsoft.com/windows/desktop/Tapi/line-createdialoginstance) message.

### `lpParams`

Pointer to a memory area used to hold a parameter block. The contents of this parameter block are specific to the service provider and its associated UI DLL.

### `dwSize`

The size in bytes of the parameter block. If the *lpParams* parameter is a pointer to a string, the size must include the **null** terminator.

## Return value

Returns zero if successful, or one of these negative error values:

LINEERR_INVALPARAM, LINEERR_NOMEM, LINEERR_OPERATIONFAILED.

## See also

[LINE_CREATEDIALOGINSTANCE](https://learn.microsoft.com/windows/desktop/Tapi/line-createdialoginstance)

[TUISPIDLLCALLBACK](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-tuispidllcallback)