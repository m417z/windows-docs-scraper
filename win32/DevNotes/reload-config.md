# reload\_config function

Reloads an IME configuration from the HKCU registry, in Japanese IME only.

## Parameters

This function has no parameters.

## Return value

This function returns **TRUE** if it succeeds; otherwise, it returns **FALSE**.

## Remarks

If no registry value is present in HKCU, the **reload\_config** function writes initial data to the registry.

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------|
| DLL<br> | Imejpknl.dll;

Imejp98k.dll |