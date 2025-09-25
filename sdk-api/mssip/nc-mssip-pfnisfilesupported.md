# pfnIsFileSupported callback function

## Description

The **pfnIsFileSupported** callback function queries the [subject interface packages](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIPs) listed in the registry to determine which SIP handles the file type.

## Parameters

### `hFile` [in]

A handle to the file.

### `pgSubject` [out]

The GUID that identifies the SIP that handles the file type.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**. For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the SIP supports the file type passed by *hfile*, the function returns **TRUE**, and sets *pgSubject* to the GUID that identifies the SIP for handling the file type.

Each SIP implements its own version of the function that determines whether the file type is supported. The specific name of the function may vary depending on the implementation of the SIP, but the signature of the function will match that of the [SIP_ADD_NEWPROVIDER](https://learn.microsoft.com/windows/desktop/api/mssip/ns-mssip-sip_add_newprovider) structure.