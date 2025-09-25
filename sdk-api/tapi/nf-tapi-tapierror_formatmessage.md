# TAPIERROR_FORMATMESSAGE macro

## Description

The
**TAPIERROR_FORMATMESSAGE** macro generates an identifier for standard TAPI error codes that can be used in the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function.

## Parameters

#### - ErrCode

TAPI error code.

## Remarks

This mechanism should be used only for displaying information on errors for which the application has no defined method of recovery (that is, unexpected or internal errors). In most cases (unlike the following simplified example), it is desirable to include additional text informing the user of actions the application takes (or the user should take) as a result of the unhandled error.

If the application gets an error result from any TAPI function, the error value can be passed to the
**TAPIERROR_FORMATMESSAGE** macro, which generates the message identifier to be passed to **FormatMessage**.

#### Examples

The following example uses **FormatMessage** to produce an error string that corresponds to a TAPI error code.

``` syntax
lResult = lineClose(hLine);

if (lResult < 0)
{
    FormatMessage(FORMAT_MESSAGE_FROM_HMODULE,
                  (LPCVOID)GetModuleHandle("TAPIUI.DLL"),
                  TAPIERROR_FORMATMESSAGE(lResult),
                  0,
                  (LPTSTR)pBuf,
                  BUFSIZE,
                  NULL);
    MessageBox(hWnd,pBuf,"TAPI ERROR",MB_OK);
}
```