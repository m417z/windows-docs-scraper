# RasAdminReleaseIpAddress callback function

\[The **RasAdminReleaseIpAddress** function is available for use in Windows NT 4.0 and is unavailable in subsequent versions. Instead, use [**MprAdminReleaseIpAddress**](https://learn.microsoft.com/windows/desktop/api/Mprapi/nf-mprapi-mpradminreleaseipaddress).\]

The **RasAdminReleaseIpAddress** function is an application-defined function that is exported by a third-party RAS server administration DLL. RAS calls this function to notify the DLL that the remote client was disconnected and that the IP address should be released.

## Parameters

*lpszUserName* \[in\]

Specifies the pointer to a null-terminated Unicode string that specifies the name of a remote user for whom an IP address was previously obtained using the [**RasAdminGetIpAddressForUser**](https://learn.microsoft.com/windows/win32/rras/rasadmingetipaddressforuser) function.

*lpszPortName* \[in\]

Pointer to a null-terminated Unicode string that specifies the name of the port on which the user specified by *lpszUserName* is connected.

*pipAddress* \[in\]

Pointer to an **IPADDR** variable that specifies the IP address returned for this user in a previous call to [**RasAdminGetIpAddressForUser**](https://learn.microsoft.com/windows/win32/rras/rasadmingetipaddressforuser).

## Return value

There is no extended error information for this function; do no call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The RAS server calls the **RasAdminReleaseIpAddress** function only if the application returned **TRUE** in the *bNotifyRelease* parameter during the earlier call to [**RasAdminGetIpAddressForUser**](https://learn.microsoft.com/windows/win32/rras/rasadmingetipaddressforuser) for the user specified by the *lpszUserName* parameter.

The setup program for a third-party RAS administration DLL must register the DLL with RAS by providing information under the following key in the registry:

```
HKEY_LOCAL_MACHINE
   SOFTWARE
      Microsoft
         RAS
            AdminDll
```

To register the DLL, set the following values under this key.

| Value name | Value data |
|---------------|-------------------------------------------------------------------------------|
| *DisplayName* | A **REG\_SZ** string that contains the user-friendly display name of the DLL. |
| *DLLPath* | A **REG\_SZ** string that contains the full path of the DLL. |

For example, the registry entry for a RAS administration DLL from a fictional company named ProElectron, Inc. might be:

```
HKEY_LOCAL_MACHINE
   SOFTWARE
      Microsoft
         RAS
            AdminDll
```

*DisplayName*: **REG\_SZ** : ProElectron RAS Admin DLL *DLLPath*: **REG\_SZ** : C:\\nt\\system32\\ntwkadm.dll

The setup program for a RAS administration DLL should also provide remove/uninstall functionality. If a user removes the DLL, the setup program should delete the DLL's registry entries.

