# NetShareCheck function

## Description

Checks whether or not a server is sharing a device.

## Parameters

### `servername` [in]

Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `device` [in]

Pointer to a string that specifies the name of the device to check for shared access.

### `type` [out]

Pointer to a variable that receives a bitmask of flags that specify the type of the shared device. This parameter is set only if the function returns successfully.

One of the following flags may be specified.

| Value | Meaning |
| --- | --- |
| **STYPE_DISKTREE** | Disk drive. |
| **STYPE_PRINTQ** | Print queue. |
| **STYPE_DEVICE** | Communication device. |
| **STYPE_IPC** | Interprocess communication (IPC). |

In addition, one or both of the following flags may be specified.

| Value | Meaning |
| --- | --- |
| **STYPE_SPECIAL** | Special share reserved for interprocess communication (IPC$) or remote administration of the server (ADMIN$). Can also refer to administrative shares such as C$, D$, E$, and so forth. For more information, see [Network Share Functions](https://learn.microsoft.com/windows/desktop/NetShare/network-share-functions). |
| **STYPE_TEMPORARY** | A temporary share. |

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory is available. |
| **NERR_DeviceNotShared** | The device is not shared. |

## Remarks

This function applies only to Server Message Block (SMB) shares. For other types of shares, such as Distributed File System (DFS) or WebDAV shares, use [Windows Networking (WNet) functions](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-functions), which support all types of shares.

No special group membership is required to successfully execute the
**NetShareCheck** function.

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management share functions. For more information, see
[IADsFileShare](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsfileshare).

#### Examples

The following code sample demonstrates how to check whether a server is sharing a device, using a call to the
**NetShareCheck** function. The function returns the type of device being shared, as described in the preceding documentation for the *type* parameter.

```cpp
#ifndef UNICODE
#define UNICODE
#endif
#include <windows.h>
#include <stdio.h>
#include <lm.h>
#pragma comment(lib, "Netapi32.lib")

void wmain( int argc, TCHAR *argv[ ])
{
   NET_API_STATUS res;
   DWORD devType = 0;

   if(argc<3)
      printf("Usage: NetShareCheck server device\n");
   else
   {
      //
      // Call the NetShareCheck function.
      //
      res=NetShareCheck(argv[1], argv[2], &devType);
      //
      // If the function succeeds, inform the user.
      //
      if(res==0)
         printf("Device is shared as type %u.\n",devType);
      //
      // Otherwise, print the error.
      //
      else
         printf("Error: %u\n", res);
   }
   return;
}

```

## See also

[NetShareEnum](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netshareenum)

[NetShareGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharegetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Share Functions](https://learn.microsoft.com/windows/desktop/NetShare/network-share-functions)