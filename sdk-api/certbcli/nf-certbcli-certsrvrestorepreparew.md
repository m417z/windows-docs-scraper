# CertSrvRestorePrepareW function

## Description

The **CertSrvRestorePrepare** function prepares a Certificate Services instance for restore operations.

## Parameters

### `pwszServerName` [in]

A pointer to the computer name of the server to prepare for restore operations. This name can be the NetBIOS name or the DNS name.

### `dwRestoreFlags` [in]

A bitfield that represents the combination of values in the following table.

| Value | Meaning |
| --- | --- |
| **CSRESTORE_TYPE_FULL** | Restore Certificate Services database, logs, and related files. |

### `phbc` [out]

A pointer to a Certificate Services backup context handle (**HCSBC**).

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success, and **phbc* is set to an **HCSBC**, which can be used by other Certificate Services restore APIs.

## Remarks

Before a Certificate Services restore operation can occur, it is necessary to create an **HCSBC** by means of **CertSrvRestorePrepare**. This **HCSBC** can be used by various Certificate Services restore functions.

**Note** When the restore session is completed, it is necessary to call [CertSrvRestoreEnd](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvrestoreend) to release the **HCSBC** which resulted from the call to **CertSrvRestorePrepare**.

This function's name in Certadm.dll is **CertSrvRestorePrepareW**. You must use this form of the name when calling [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress). Also, this function is defined as type **FNCERTSRVRESTOREPREPAREW** in the Certbcli.h header file.

To execute this call, you must have the restore [privilege](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). For more information, see
[Setting the Backup and Restore Privileges](https://learn.microsoft.com/windows/desktop/SecCrypto/setting-the-backup-and-restore-privileges).

#### Examples

```cpp
FNCERTSRVRESTOREPREPAREW*  pfnRestorePrepare;
char * szRestorePrepFunc = "CertSrvRestorePrepareW";
HCSBC      hCSBC=NULL;
HINSTANCE  hInst=0;
HRESULT    hr=0;

// Load the DLL.
hInst = LoadLibrary(L"Certadm.dll");
if ( NULL == hInst )
{
    printf("Failed LoadLibrary,error=%d\n",
           GetLastError() );
    exit(1); // Or other appropriate error action.
}

// Get the address for the desired function.
pfnRestorePrepare = (FNCERTSRVRESTOREPREPAREW*)GetProcAddress( hInst,
                                          szRestorePrepFunc );
if ( NULL == pfnRestorePrepare )
{
    printf("Failed GetProcAddress - %s, error=%d\n",
           szRestorePrepFunc,
           GetLastError() );
    exit(1); // Or other appropriate error action.
}

// Prepare CertServ for restoration.
hr = pfnRestorePrepare(wszServer,
                       CSRESTORE_TYPE_FULL,
                       &hCSBC);

if (FAILED(hr))
{
    printf("Failed pfnRestorePrepare call [%x]\n", hr);
    exit(1); // Or other appropriate error action.
}

// Use the HCSBC for restore operations.
// ...

// When done processing, release the HCSBC context
// by calling CertSrvRestoreEnd (not shown here).
// ...

// Free the DLL.
if (hInst)
    FreeLibrary(hInst);
```

## See also

[CertSrvRestoreEnd](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvrestoreend)

[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress)

[Setting the Backup and Restore Privileges](https://learn.microsoft.com/windows/desktop/SecCrypto/setting-the-backup-and-restore-privileges)

[Using the Certificate Services Backup and Restore Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/using-the-certificate-services-backup-and-restore-functions)