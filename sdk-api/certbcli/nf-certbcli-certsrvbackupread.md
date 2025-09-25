# CertSrvBackupRead function

## Description

The **CertSrvBackupRead** function reads bytes from a Certificate Services file.

## Parameters

### `hbc` [in]

A handle to a Certificate Services backup context.

### `pvBuffer` [out]

Void pointer to storage which will contain bytes read from the file being backed up.

### `cbBuffer` [in]

Size of the storage area referenced by *pvBuffer*.

### `pcbRead` [out]

A pointer to a **DWORD** value which represents the actual number of bytes read by **CertSrvBackupRead**. The number of bytes read can be less than the size of the storage area allocated to *pvBuffer* if the end of the file has been reached.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success.

## Remarks

After opening the file for backup purposes (using
[CertSrvBackupOpenFile](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupopenfilew)), call **CertSrvBackupRead** to retrieve the contents of the file, and call an application-specific routine to write the contents to a backup medium. **CertSrvBackupRead** and the application-specific routine can be placed in a loop until all the bytes of the file are read and backed up. When done reading the file, close it by calling
[CertSrvBackupClose](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupclose).

#### Examples

```cpp

#include <windows.h>
#include <stdio.h>
#include <Certbcli.h>

#define BUFFSIZE 524288

FNCERTSRVBACKUPREAD* pfnRead;
char * szBackupReadFunc = "CertSrvBackupRead";
BYTE       ReadBuff[BUFFSIZE];
DWORD      cbRead=0;
HRESULT    hr=0;

// Get the address for the desired function.
// hInst was set by calling LoadLibrary for Certadm.dll.
pfnRead = (FNCERTSRVBACKUPREAD*)GetProcAddress(hInst,
                                          szBackupReadFunc);
if ( NULL == pfnRead )
{
    printf("Failed GetProcAddress - %s, error=%d\n",
           szBackupReadFunc,
           GetLastError() );
    exit(1); // Or other appropriate error action.
}

// Read the file.
// hCSBC represents an HCSBC used in
// an earlier call to CertSrvBackupOpenFile.
// To read the entire file, this code
// would be placed in a loop.
hr = pfnRead( hCSBC,
              &ReadBuff,
              BUFFSIZE,
              &cbRead );
if (FAILED(hr))
{
    printf("Failed pfnRead call [%x]\n", hr);
    exit(1); // Or other appropriate error action.
}

// Use the bytes read as needed. For example,
// in an application-specific routine to back
// up the file contents.
// ...
```

## See also

[CertSrvBackupClose](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupclose)

[CertSrvBackupOpenFile](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupopenfilew)

[Using the Certificate Services Backup and Restore Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/using-the-certificate-services-backup-and-restore-functions)