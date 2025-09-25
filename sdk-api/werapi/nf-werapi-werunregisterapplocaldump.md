# WerUnregisterAppLocalDump function

## Description

Cancels the registration that was made through the [WerRegisterAppLocalDump](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werregisterapplocaldump) function, which specifies that [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) should save a copy of the diagnostic memory dump that WER collects when one of the processes for the application stops responding.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[WerRegisterAppLocalDump](https://learn.microsoft.com/windows/desktop/api/werapi/nf-werapi-werregisterapplocaldump), [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER)