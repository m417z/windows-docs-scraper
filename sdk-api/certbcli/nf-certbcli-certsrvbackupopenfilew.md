# CertSrvBackupOpenFileW function

## Description

The **CertSrvBackupOpenFile** function opens a file for backup.

## Parameters

### `hbc` [in]

A handle to a [Certificate Services](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) backup context.

### `pwszAttachmentName` [in]

File name to open for backup purposes. This file name would be parsed from a list produced by means of
[CertSrvBackupGetBackupLogs](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupgetbackuplogsw) or
[CertSrvBackupGetDatabaseNames](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupgetdatabasenamesw). Note that the names returned by **CertSrvBackupGetBackupLogs** and **CertSrvBackupGetDatabaseNames** must have the single-WCHAR CSBFT_* prefix stripped before **CertSrvBackupOpenFile** is called.

### `cbReadHintSize` [in]

Number of bytes used as a hint when the file is read by
[CertSrvBackupRead](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupread). The *cbReadHintSize* parameter passed to the first **CertSrvBackupOpenFile** call for the backup context is used to size the read buffer. Pass zero for this parameter, and the buffer will be sized at a reasonably efficient size chosen by **CertSrvBackupOpenFile**. If insufficient memory is available, the buffer size will be reduced until memory allocation succeeds or until the buffer size reaches its minimum possible value. Pass a nonzero size to cause **CertSrvBackupOpenFile** to size the buffer to a power of two near the value of *cbReadHintSize*. The implementation will choose only powers of two between 64 KB and 4 MB.

### `pliFileSize` [out]

A pointer to a **LARGE_INTEGER** value that represents the number of bytes in the file.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Use this function to open a file for backup purposes. When you have finished using the file, close the file by calling
the [CertSrvBackupClose](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupclose) function.

The name of this function in Certadm.dll is **CertSrvBackupOpenFileW**. You must use this form of the name when calling [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress). Also, this function is defined as type **FNCERTSRVBACKUPOPENFILEW** in Certbcli.h.

#### Examples

```cpp
FNCERTSRVBACKUPOPENFILEW* pfnOpenFile;
char * szBackupOpenFunc = "CertSrvBackupOpenFileW";
LARGE_INTEGER liFileSize;
HRESULT       hr=0;

// Get the address for the desired function.
// hInst was set by calling LoadLibrary for Certadm.dll.
pfnOpenFile = (FNCERTSRVBACKUPOPENFILEW*)GetProcAddress(hInst,
                                         szBackupOpenFunc);
if ( NULL == pfnOpenFile )
{
    printf("Failed GetProcAddress - %s, error=%d\n",
            szBackupOpenFunc,
            GetLastError() );
    exit(1); // or other appropriate error action
}

// Open the file.
// hCSBC was set by an earlier call to CertSrvBackupPrepare.
// pwszFile specifies the name of a file.
// This name could have resulted from parsing the
// output from CertSrvBackupGetDatabaseNames, and so on.
hr = pfnOpenFile(hCSBC,
                pwszFile,
                0,
                &liFileSize);
if (FAILED(hr))
{
    printf("Failed pfnOpenFile call [%x] %ws\n",
           hr,
           pwszFile);
           exit(1); // Or other appropriate error action.
}

// Use the opened file as needed.
// When you have finished using the file, call CertSrvBackupClose.
// ...
```

## See also

[CertSrvBackupClose](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupclose)

[CertSrvBackupRead](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupread)

[Using the Certificate Services Backup and Restore Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/using-the-certificate-services-backup-and-restore-functions)