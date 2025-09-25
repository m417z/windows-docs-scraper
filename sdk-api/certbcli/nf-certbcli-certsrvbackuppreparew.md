# CertSrvBackupPrepareW function

## Description

The **CertSrvBackupPrepare** function is used to prepare a Certificate Services server for backup operations.

## Parameters

### `pwszServerName` [in]

A pointer to the machine name of the server to prepare for online backup. This name can be the NetBIOS name or the DNS name.

### `grbitJet` [in]

Value used by the database engine; this value should be set to zero.

### `dwBackupFlags` [in]

Specifies the backup type. This can be either of the following values.

| Value | Meaning |
| --- | --- |
| **CSBACKUP_TYPE_FULL** | Backup the Certificate Services database, logs and related files. |
| **CSBACKUP_TYPE_LOGS_ONLY** | Backup the log files only. |

### `phbc` [out]

A pointer to a Certificate Services backup context handle (**HCSBC**).

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success, and **phbc* will be set to an **HCSBC** which can be used by other Certificate Services backup APIs.

## Remarks

Before a Certificate Services backup can occur, it is necessary to create an **HCSBC** by means of **CertSrvBackupPrepare**. The resulting **HCSBC** is a necessary parameter of Certificate Services backup functions which can be used to list, open, read, and close files, as well as truncate the log files.

**Note** When the backup session is completed, it is necessary to call
[CertSrvBackupEnd](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupend) to release the **HCSBC** which resulted from the call to **CertSrvBackupPrepare**.

This function's name in Certadm.dll is **CertSrvBackupPrepareW**. You must use this form of the name when calling [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress). Also, this function is defined as type **FNCERTSRVBACKUPPREPAREW** in the Certbcli.h header file.

To execute this call, you must have the backup [privilege](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). For details, see
[Setting the Backup and Restore Privileges](https://learn.microsoft.com/windows/desktop/SecCrypto/setting-the-backup-and-restore-privileges).

#### Examples

```cpp
WCHAR *    wszServer = L"MyCertServerMachine";
FNCERTSRVBACKUPPREPAREW* pfnBackupPrepare;
char * szBackPrepFunc = "CertSrvBackupPrepareW";
HINSTANCE  hInst=0;
HCSBC      hCSBC=NULL;
HRESULT    hr=0;

// Load the DLL.
hInst = LoadLibrary(L"Certadm.dll");
if ( NULL == hInst )
{
    printf("Failed LoadLibrary, error=%d\n",
            GetLastError() );
    exit(1); // Or other appropriate error action.
}
// Get the address for the desired function.
pfnBackupPrepare = (FNCERTSRVBACKUPPREPAREW*)GetProcAddress( hInst,
                                        szBackPrepFunc );
if ( NULL == pfnBackupPrepare )
{
    printf("Failed GetProcAddress - %s, error=%d\n",
           szBackPrepFunc,
           GetLastError() );
    exit(1); // Or other appropriate error action.
}

// Prepare CertServ for backup.
hr = pfnBackupPrepare(wszServer,
                      0,
                      CSBACKUP_TYPE_FULL,
                      &hCSBC);
if (FAILED(hr))
{
    printf("Failed pfnBackupPrepare call [%x]\n", hr);
    exit(1); // Or other appropriate error action.
}

// Use the HCSBC for backup operations.
// ...

// When done processing, release the HCSBC context
// by calling CertSrvBackupEnd (not shown here).
// ...

// Done processing, free the DLL.
if (hInst)
    FreeLibrary(hInst);

```

## See also

[CertSrvBackupEnd](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupend)

[Using the Certificate Services Backup and Restore Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/using-the-certificate-services-backup-and-restore-functions)