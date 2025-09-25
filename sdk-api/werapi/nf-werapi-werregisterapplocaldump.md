# WerRegisterAppLocalDump function

## Description

Registers a path (relative to the [LocalFolder](https://learn.microsoft.com/uwp/api/windows.storage.applicationdata.localfolder) of the packaged application) where a copy should be saved of the diagnostic memory dump that [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) collects when one of the processes for the application stops responding.

## Parameters

### `localAppDataRelativePath` [in]

The path relative to the local app store for the calling application. This is where a copy is saved of the diagnostic memory dump that WER collects when one of the processes for the application stops responding. The maximum length for this relative path in characters is **WER_MAX_LOCAL_DUMP_SUBPATH_LENGTH**, which has a value of 64. This maximum length includes the null-termination character.

## Return value

This function returns **S_OK** on success or an error code on failure, including the following error codes.

|Return code|Description|
|--- |--- |
|**WER_E_INVALID_STATE**|The process cannot store the memory dump, or WER cannot create a location to store the memory dump.|
|**E_INVALIDARG**|The *localAppDataRelativePath* parameter is NULL or is longer than 64 characters.|

## Remarks

A packaged application calls **WerRegisterAppLocalDump** when the application launches to request a copy of the diagnostic memory dump that WER collects if or when one of the processes for the application stops responding.

WER does not manage storage at the location that the relative path specifies or the number of memory dumps that are collected for the application.

## See also

[WerUnregisterAppLocalDump function](https://learn.microsoft.com/windows/win32/api/werapi/nf-werapi-werunregisterapplocaldump), [Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)