# NetValidateName function

## Description

The
**NetValidateName** function verifies that a name is valid for name type specified(computer name, workgroup name, domain name, or DNS computer name).

## Parameters

### `lpServer` [in]

A pointer to a constant string that specifies the DNS or NetBIOS name of the computer on which to call the function. If this parameter is **NULL**, the local computer is used.

### `lpName` [in]

A pointer to a constant string that specifies the name to validate. Depending on the value specified in the *NameType* parameter, the *lpName* parameter can point to a computer name, workgroup name, domain name, or DNS computer name.

### `lpAccount` [in]

If the *lpName* parameter is a domain name, this parameter points to an account name to use when connecting to the domain controller. The string must specify either a domain NetBIOS name and user account (for example, "REDMOND\user") or the user principal name (UPN) of the user in the form of an Internet-style login name (for example, "someone@example.com"). If this parameter is **NULL**, the caller's context is used.

### `lpPassword` [in]

If the *lpAccount* parameter specifies an account name, this parameter must point to the password to use when connecting to the domain controller. Otherwise, this parameter must be **NULL**.

### `NameType` [in]

The type of the name passed in the *lpName* parameter to validate. This parameter can be one of the values from the NETSETUP_NAME_TYPE enumeration type defined in the *Lmjoin.h* header file.

Note that the *Lmjoin.h* header is automatically included by the *Lm.h* header file. The *Lmjoin.h* header files should not be used directly.

 The following list shows the possible values for this parameter.

| Value | Meaning |
| --- | --- |
| **NetSetupUnknown**<br><br>0 | The nametype is unknown. If this value is used, the **NetValidateName** function fails with **ERROR_INVALID_PARAMETER**. |
| **NetSetupMachine**<br><br>1 | Verify that the NetBIOS computer name is valid and that it is not in use. |
| **NetSetupWorkgroup**<br><br>2 | Verify that the workgroup name is valid. |
| **NetSetupDomain**<br><br>3 | Verify that the domain name exists and that it is a domain. |
| **NetSetupNonExistentDomain**<br><br>4 | Verify that the domain name is not in use. |
| **NetSetupDnsMachine**<br><br>5 | Verify that the DNS computer name is valid.<br><br>This value is supported on Windows 2000 and later. The application must be compiled with **_WIN32_WINNT >= 0x0500** to use this value. |

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **DNS_ERROR_INVALID_NAME_CHAR** | The DNS name contains an invalid character. This error is returned if the *NameType* parameter specified is **NetSetupDnsMachine** and the DNS name in the *lpName* parameter contains an invalid character. |
| **DNS_ERROR_NON_RFC_NAME** | The DNS name does not comply with RFC specifications. This error is returned if the *NameType* parameter specified is **NetSetupDnsMachine** and the DNS name in the *lpName* parameter does not comply with RFC specifications. |
| **ERROR_DUP_NAME** | A duplicate name already exists on the network. |
| **ERROR_INVALID_COMPUTERNAME** | The format of the specified computer name is not valid. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This error is returned if the *lpName* parameter is **NULL** or the *NameType* parameter is specified as **NetSetupUnknown** or an unknown nametype. |
| **ERROR_NO_SUCH_DOMAIN** | The specified domain does not exist. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if a remote computer was specified in the *lpServer* parameter and this call is not supported on the remote computer. |
| **NERR_InvalidComputer** | The specified computer name is not valid. This error is returned if the *NameType* parameter specified is **NetSetupDnsMachine** or **NetSetupMachine** and the specified computer name is not valid. |
| **NERR_InvalidWorkgroupName** | The specified workgroup name is not valid. This error is returned if the *NameType* parameter specified is **NetSetupWorkgroup** and the specified workgroup name is not valid. |
| **RPC_S_SERVER_UNAVAILABLE** | The RPC server is not available. This error is returned if a remote computer was specified in the *lpServer* parameter and the RPC server is not available. |
| **RPC_E_REMOTE_DISABLED** | Remote calls are not allowed for this process. This error is returned if a remote computer was specified in the *lpServer* parameter and remote calls are not allowed for this process. |

## Remarks

The
**NetValidateName** function validates a name based on the nametype specified.

If the *NameType* parameter is **NetSetupMachine**, the name passed in the *lpName* parameter must be syntactically correct as a NetBIOS name and the name must not currently be in use on the network.

If the *NameType* parameter is **NetSetupWorkgroup**, the name passed in the *lpName* parameter must be syntactically correct as a NetBIOS name, the name must not currently be in use on the network as a unique name, and the name must be different from the computer name.

If the *NameType* parameter is **NetSetupDomain**, the name passed in the *lpName* parameter must be syntactically correct as a NetBIOS or DNS name and the name must currently be registered as a domain name.

If the *NameType* parameter is **NetSetupNonExistentDomain**, the name passed in the *lpName* parameter must be syntactically correct as a NetBIOS or DNS name and the name must currently not be registered as a domain name.

If the *NameType* parameter is **NetSetupDnsMachine**, the name passed in the *lpName* parameter must be syntactically correct as a DNS name.

NetBIOS names are limited to maximum length of 16 characters.

No special group membership is required to successfully execute the
**NetValidateName** function.

#### Examples

The following example validates a name for a specific type.

```cpp
#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib, "netapi32.lib")

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <windows.h>
#include <lm.h>

int wmain(int argc, wchar_t * argv[])
{

    NET_API_STATUS nStatus;

    LPCWSTR lpServer = NULL;
    LPCWSTR lpName = NULL;
    LPCWSTR lpAccount = NULL;
    LPCWSTR lpPassword = NULL;
    DWORD dwNameType = NetSetupUnknown; // unknown name type

    if (argc != 3 && argc != 4 && argc != 6) {
        wprintf(L"Usage: %ws Server Name AccountName Password> nametype\n",
                argv[0]);
        wprintf(L"Usage: %ws Server Name nametype\n", argv[0]);
        wprintf(L"Usage: %ws Name nametype\n", argv[0]);
        wprintf(L"     %ws Client2 2\n", argv[0]);
        wprintf(L"     %ws Myserver Client2 3\n", argv[0]);
        wprintf(L"     %ws Myserver Client2 domain\\user password 3\n", argv[0]);
        exit(1);
    }
    // The request is not for the primary domain.
    //
    if (argc == 3) {
        lpName = argv[1];
        dwNameType = _wtoi(argv[2]);
    }

    if (argc == 4) {
        lpServer = argv[1];
        lpName = argv[2];
        dwNameType = _wtoi(argv[3]);
    }

    if (argc == 6) {
        lpServer = argv[1];
        lpName = argv[2];
        lpAccount = argv[3];
        lpPassword = argv[4];
        dwNameType = _wtoi(argv[5]);
    }

    wprintf(L"Calling NetValidateName with parameters\n");
    wprintf(L"    lpServer = %ws\n", lpServer);
    wprintf(L"    lpName = %ws\n", lpName);
    wprintf(L"    lpAccount = %ws\n", lpAccount);
    wprintf(L"    lpPassword = %ws\n", lpPassword);
    wprintf(L"    NameType  = %d ", dwNameType);
    switch (dwNameType) {
    case NetSetupUnknown:
        wprintf(L"(NetSetupUnknown)\n");
        break;
    case NetSetupMachine:
        wprintf(L"(NetSetupMachine)\n");
        break;
    case NetSetupWorkgroup:
        wprintf(L"(NetSetupWorkgroup)\n");
        break;
    case NetSetupDomain:
        wprintf(L"(NetSetupDomain)\n");
        break;
    case NetSetupNonExistentDomain:
        wprintf(L"(NetSetupNonExistentDomain)\n");
        break;
#if(_WIN32_WINNT >= 0x0500)
    case NetSetupDnsMachine:
        wprintf(L"(NetSetupDnsMachine)\n");
        break;
#endif
    default:
        wprintf(L"Other unknown nametype)\n");
        break;
    }

    //
    // Call the NetValidateName function to validate the name
    //
    nStatus = NetValidateName(lpServer,
                              lpName, lpAccount, lpPassword, (NETSETUP_NAME_TYPE) dwNameType);
    //
    // If the call succeeds,
    //
    if ((nStatus == NERR_Success)) {
        wprintf(L"NetValidateName was successful\n", nStatus);
    } else {
        wprintf(L"NetValidateName failed with error: %lu (0x%lx)\n", nStatus,
                nStatus);
        wprintf(L"   Error = ");
        switch (nStatus) {
        case ERROR_INVALID_PARAMETER:
            wprintf(L"ERROR_INVALID_PARAMETER\n");
            break;
        case ERROR_DUP_NAME:
            wprintf(L"ERROR_DUP_NAME\n");
            break;
        case ERROR_NO_SUCH_DOMAIN:
            wprintf(L"ERROR_NO_SUCH_DOMAIN\n");
            break;
        case ERROR_NOT_SUPPORTED:
            wprintf(L"ERROR_NOT_SUPPORTED\n");
            break;
        case ERROR_INVALID_COMPUTERNAME:
            wprintf(L"ERROR_INVALID_COMPUTERNAME\n");
            break;
        case DNS_ERROR_INVALID_NAME_CHAR:
            wprintf(L"DNS_ERROR_INVALID_NAME_CHAR\n");
            break;
        case DNS_ERROR_NON_RFC_NAME:
            wprintf(L"DNS_ERROR_NON_RFC_NAME\n");
            break;
        case NERR_InvalidComputer:
            wprintf(L"NERR_InvalidComputer\n");
            break;
        case NERR_InvalidWorkgroupName:
            wprintf(L"NERR_InvalidWorkgroupName\n");
            break;
        case RPC_S_SERVER_UNAVAILABLE:
            wprintf(L"RPC_S_SERVER_UNAVAILABLE\n");
            break;
        case RPC_E_REMOTE_DISABLED:
            wprintf(L"RPC_E_REMOTE_DISABLED\n");
            break;
        default:
            wprintf(L"Other error, see Winerror.h or lmerr.h)\n");
            break;
        }
    }

    return nStatus;
}

```

## See also

[Directory Service Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/directory-service-functions)

[NetGetJoinInformation](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netgetjoininformation)

[NetGetJoinableOUs](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netgetjoinableous)

[NetJoinDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netjoindomain)

[NetRenameMachineInDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrenamemachineindomain)

[NetUnjoinDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netunjoindomain)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)