# CryptSIPRetrieveSubjectGuidForCatalogFile function

## Description

The **CryptSIPRetrieveSubjectGuidForCatalogFile** function retrieves the subject GUID associated with the specified file.

## Parameters

### `FileName` [in]

The name of the file. If the *hFileIn* parameter is set, the value in this parameter is ignored.

### `hFileIn` [in, optional]

A handle to the file to check. This parameter must contain a valid handle if the *FileName* parameter is **NULL**.

### `pgSubject` [out]

A globally unique ID that identifies the subject.

## Return value

The return value is **TRUE** if the function succeeds; otherwise, **FALSE**.

If this function returns **FALSE**, additional error information can be obtained by calling the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. **GetLastError** will return one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters are not valid. |

## Remarks

This function only supports [subject interface packages](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIPs) that are used for portable executable images (.exe), cabinet (.cab) images, and flat files.