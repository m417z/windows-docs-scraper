# NetShareEnum function

## Description

Retrieves information about each shared resource on a server.

You can also use the
[WNetEnumResource](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetenumresourcea) function to retrieve resource information. However, **WNetEnumResource** does not enumerate hidden shares or users connected to a share.

## Parameters

### `servername` [in]

Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Return share names. The *bufptr* parameter points to an array of [SHARE_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_0) structures. |
| **1** | Return information about shared resources, including the name and type of the resource, and a comment associated with the resource. <br><br>The *bufptr* parameter points to an array of [SHARE_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1) structures. |
| **2** | Return information about shared resources, including name of the resource, type and permissions, password, and number of connections. The *bufptr* parameter points to an array of [SHARE_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_2) structures. |
| **502** | Return information about shared resources, including name of the resource, type and permissions, number of connections, and other pertinent information. The *bufptr* parameter points to an array of [SHARE_INFO_502](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_502) structures. Shares from different scopes are not returned. For more information about scoping, see the Remarks section of the documentation for the [NetServerTransportAddEx](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportaddex) function. |
| **503** | Return information about shared resources, including the name of the resource, type and permissions, number of connections, and other pertinent information. The *bufptr* parameter points to an array of [SHARE_INFO_503](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_503) structures. Shares from all scopes are returned. If the **shi503_servername** member of this structure is "*", there is no configured server name and the **NetShareEnum** function enumerates shares for all the unscoped names.<br><br>**Windows Server 2003 and Windows XP:** This information level is not supported. |

### `bufptr` [out]

Pointer to the buffer that receives the data. The format of this data depends on the value of the *level* parameter.

This buffer is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function. Note that you must free the buffer even if the function fails with **ERROR_MORE_DATA**.

### `prefmaxlen` [in]

Specifies the preferred maximum length of returned data, in bytes. If you specify **MAX_PREFERRED_LENGTH**, the function allocates the amount of memory required for the data. If you specify another value in this parameter, it can restrict the number of bytes that the function returns. If the buffer size is insufficient to hold all entries, the function returns **ERROR_MORE_DATA**. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

### `entriesread` [out]

Pointer to a value that receives the count of elements actually enumerated.

### `totalentries` [out]

Pointer to a value that receives the total number of entries that could have been enumerated. Note that applications should consider this value only as a hint.

### `resume_handle` [in, out]

Pointer to a value that contains a resume handle which is used to continue an existing share search. The handle should be zero on the first call and left unchanged for subsequent calls. If *resume_handle* is **NULL**, then no resume handle is stored.

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

This function applies only to Server Message Block (SMB) shares. For other types of shares, such as Distributed File System (DFS) or WebDAV shares, use [Windows Networking (WNet) functions](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-functions), which support all types of shares.

For interactive users (users who are logged on locally to the machine), no special group membership is required to execute the **NetShareEnum** function. For non-interactive users, Administrator, Power User, Print Operator, or Server Operator group membership is required to successfully execute the
**NetShareEnum** function at levels 2, 502, and 503. No special group membership is required for level 0 or level 1 calls.

**Windows Server 2022:**  For non-interactive users, Administrator, Access Control Assistance Operators, or Server Operator group membership is required to successfully execute the
**NetShareEnum** function at levels 2, 502, and 503.

**Windows Server 2003 and Windows XP:** For all users, Administrator, Power User, Print Operator, or Server Operator group membership is required to successfully execute the
**NetShareEnum** function at levels 2 and 502.

To retrieve a value that indicates whether a share is the root volume in a DFS tree structure, you must call the
[NetShareGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharegetinfo) function and specify information level 1005.

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management share functions. For more information, see
[IADsFileShare](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsfileshare).

#### Examples

The following code sample demonstrates how to retrieve information about each shared resource on a server using a call to the
**NetShareEnum** function. The sample calls
**NetShareEnum**, specifying information level 502 ([SHARE_INFO_502](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_502)). If the call succeeds, the code loops through the entries and prints information about each share. The sample also calls the
[IsValidSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-isvalidsecuritydescriptor) function to validate the **shi502_security_descriptor** member. Finally, the code sample frees the memory allocated for the information buffer.

```cpp
#ifndef UNICODE
#define UNICODE
#endif
#include <windows.h>
#include <stdio.h>
#include <lm.h>

#pragma comment(lib, "Netapi32.lib")
#pragma comment(lib, "Advapi32.lib")

void wmain( int argc, TCHAR *lpszArgv[ ])
{
   PSHARE_INFO_502 BufPtr,p;
   NET_API_STATUS res;
   LPTSTR   lpszServer = NULL;
   DWORD er=0,tr=0,resume=0, i;

   switch(argc)
   {
   case 2:
      lpszServer = lpszArgv[1];
      break;
   default:
      printf("Usage: NetShareEnum <servername>\n");
      return;
   }
   //
   // Print a report header.
   //
   printf("Share:              Local Path:                   Uses:   Descriptor:\n");
   printf("---------------------------------------------------------------------\n");
   //
   // Call the NetShareEnum function; specify level 502.
   //
   do // begin do
   {
      res = NetShareEnum (lpszServer, 502, (LPBYTE *) &BufPtr, MAX_PREFERRED_LENGTH, &er, &tr, &resume);
      //
      // If the call succeeds,
      //
      if(res == ERROR_SUCCESS || res == ERROR_MORE_DATA)
      {
         p=BufPtr;
         //
         // Loop through the entries;
         //  print retrieved data.
         //
         for(i=1;i<=er;i++)
         {
            printf("%-20S%-30S%-8u",p->shi502_netname, p->shi502_path, p->shi502_current_uses);
            //
            // Validate the value of the
            //  shi502_security_descriptor member.
            //
            if (IsValidSecurityDescriptor(p->shi502_security_descriptor))
               printf("Yes\n");
            else
               printf("No\n");
            p++;
         }
         //
         // Free the allocated buffer.
         //
         NetApiBufferFree(BufPtr);
      }
      else
         printf("Error: %ld\n",res);
   }
   // Continue to call NetShareEnum while
   //  there are more entries.
   //
   while (res==ERROR_MORE_DATA); // end do
   return;
}

```

## See also

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Share Functions](https://learn.microsoft.com/windows/desktop/NetShare/network-share-functions)

[SHARE_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_0)

[SHARE_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1)

[SHARE_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_2)

[SHARE_INFO_502](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_502)

[SHARE_INFO_503](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_503)