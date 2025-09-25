# CryptSIPRetrieveSubjectGuid function

## Description

The **CryptSIPRetrieveSubjectGuid** function retrieves a GUID based on the header information in a specified file. The GUID is used by the [CryptSIPLoad](https://learn.microsoft.com/windows/desktop/api/mssip/nf-mssip-cryptsipload) function to load the [subject interface package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIP) implementation for the given file type.

## Parameters

### `FileName` [in]

The name of the file.

### `hFileIn` [in, optional]

A handle to the file to check.

### `pgSubject` [out]

A GUID that identifies the subject.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**. For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).