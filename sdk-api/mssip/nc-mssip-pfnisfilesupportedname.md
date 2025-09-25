# pfnIsFileSupportedName callback function

## Description

The **pfnIsFileSupportedName** callback function queries the [subject interface packages](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIPs) listed in the registry to determine which SIP handles the file type.

## Parameters

### `pwszFileName` [in]

A pointer to a **null**-terminated string that contains the absolute path to the file to be processed by the SIP.

### `pgSubject` [out]

The GUID identifying the SIP that handles the file type.

## Return value

The return value is **TRUE** if the function succeeds; **FALSE** if the function fails. If the function fails, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to determine the reason for failure.

## Remarks

If the SIP supports the file type passed by *hfile*, the function returns **TRUE**, and sets *pgSubject* to the GUID that identifies the SIP for handling the file type.

Each SIP implements its own version of the function that determines if the file type is supported. The specific name of the function may vary depending on the implementation of the SIP, but the signature of the function will match that of the [SIP_ADD_NEWPROVIDER](https://learn.microsoft.com/windows/desktop/api/mssip/ns-mssip-sip_add_newprovider) structure.

SIPs must support a limited set of file types and file extensions. The fileSupportedName function must check that the provided file matches one of the file extensions supported by the SIP. For instance, the WSH SIP supports only the following list of file extensions and checks that the file under validation is a member of the following list: .js, .jse, .vbe, .vbs, or .wsf.

## See also

[pfnIsFileSupported](https://learn.microsoft.com/windows/desktop/api/mssip/nc-mssip-pfnisfilesupported)