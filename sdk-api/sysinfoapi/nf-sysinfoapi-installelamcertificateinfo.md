# InstallELAMCertificateInfo function

## Description

Installs the certificate information specified in the resource file, which is linked into the ELAM
driver at build time. This API is used by anti-malware vendors to launch the anti-malware software's user-mode
service as protected. For more information, see
[Protecting Anti-Malware Services](https://learn.microsoft.com/windows/desktop/Services/protecting-anti-malware-services-).

## Parameters

### `ELAMFile` [in]

A handle to an ELAM driver file which contains the resource file with the certificate information. The handle
to the ELAM driver file must be opened for read access only and must not be shared for write access.

## Return value

If the function succeeds, the return value is TRUE.

If the function fails, the return value is FALSE. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Anti-malware vendors can use this API to register their anti-malware user-mode service that needs to be
launched as protected. Note that the file handle supplied in the *hElamFile* parameter must be opened for read access
only and must not be shareable for write access.

For more information, see
[Protecting Anti-Malware Services](https://learn.microsoft.com/windows/desktop/Services/protecting-anti-malware-services-).

#### Examples

Code example:

```cpp
HANDLE FileHandle = NULL;

FileHandle = CreateFile(<Insert Elam driver file name>,
                        FILE_READ_DATA,
                        FILE_SHARE_READ,
                        NULL,
                        OPEN_EXISTING,
                        FILE_ATTRIBUTE_NORMAL,
                        NULL
                        );

if (InstallElamCertificateInfo(FileHandle) == FALSE)
{
    Result = GetLastError();
    goto exitFunc;
}
```