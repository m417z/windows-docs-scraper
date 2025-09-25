# AuxUlibInitialize function

## Description

Initializes the Aux_ulib library. This function must be called before any
other function in the library can be called.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[AuxUlibSetSystemFileCacheSize](https://learn.microsoft.com/windows/desktop/api/aux_ulib/nf-aux_ulib-auxulibsetsystemfilecachesize)