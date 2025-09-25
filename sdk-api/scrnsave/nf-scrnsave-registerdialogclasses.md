# RegisterDialogClasses function

## Description

Registers any nonstandard window classes required by a screen saver's configuration dialog box.

## Parameters

### `hInst`

Type: **HANDLE**

An identifier of an instance of the module registering the window classes.

## Return value

Type: **BOOL**

Returns nonzero if successful, or zero otherwise.

To retrieve extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **RegisterDialogClasses** function should not be exported. It is called by routines defined in the Scrnsave.lib file.

If a screen saver does not register any special window classes for the configuration dialog box, the **RegisterDialogClasses** function must return **TRUE**.

## See also

[ScreenSaverConfigureDialog](https://learn.microsoft.com/windows/desktop/api/scrnsave/nf-scrnsave-screensaverconfiguredialog)