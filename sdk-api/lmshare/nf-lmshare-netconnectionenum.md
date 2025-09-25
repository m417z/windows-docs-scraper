# NetConnectionEnum function

## Description

Lists all connections made to a shared resource on the server or all connections established from a particular computer. If there is more than one user using this connection, then it is possible to get more than one structure for the same connection, but with a different user name.

## Parameters

### `servername` [in]

Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** is defined.

### `qualifier` [in]

Pointer to a string that specifies a share name or computer name for the connections of interest. If it is a share name, then all the connections made to that share name are listed. If it is a computer name (for example, it starts with two backslash characters), then
**NetConnectionEnum** lists all connections made from that computer to the server specified.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** is defined.

### `level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Return connection identifiers. The *bufptr* parameter is a pointer to an array of [CONNECTION_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-connection_info_0) structures. |
| **1** | Return connection identifiers and connection information. The *bufptr* parameter is a pointer to an array of [CONNECTION_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-connection_info_1) structures. |

### `bufptr` [out]

Pointer to the address of the buffer that receives the information. The format of this data depends on the value of the *level* parameter.

This buffer is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function. Note that you must free the buffer even if the function fails with **ERROR_MORE_DATA**.

### `prefmaxlen` [in]

Specifies the preferred maximum length of returned data, in bytes. If you specify **MAX_PREFERRED_LENGTH**, the function allocates the amount of memory required for the data. If you specify another value in this parameter, it can restrict the number of bytes that the function returns. If the buffer size is insufficient to hold all entries, the function returns **ERROR_MORE_DATA**. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

### `entriesread` [out]

Pointer to a value that receives the count of elements actually enumerated.

### `totalentries` [out]

Pointer to a value that receives the total number of entries that could have been enumerated from the current resume position. Note that applications should consider this value only as a hint.

### `resume_handle` [in, out]

Pointer to a value that contains a resume handle which is used to continue an existing connection search. The handle should be zero on the first call and left unchanged for subsequent calls. If this parameter is **NULL**, then no resume handle is stored.

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

Administrator, Server or Print Operator, or Power User group membership is required to successfully execute the
**NetConnectionEnum** function.

#### Examples

The following code sample demonstrates how to list the connections made to a shared resource with a call to the
**NetConnectionEnum** function. The sample calls
**NetConnectionEnum**, specifying information level 1 ([CONNECTION_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-connection_info_1)). If there are entries to return, it prints the values of the **coni1_username** and **coni1_netname** members. If there are no entries to return, the sample prints an appropriate message. Finally, the code sample frees the memory allocated for the information buffer.

```cpp
#ifndef UNICODE
#define UNICODE
#endif
#include <windows.h>
#include <lm.h>
#include <stdio.h>
#pragma comment(lib, "Netapi32.lib")

void wmain(int argc, wchar_t *argv[ ])
{
   DWORD res, i, er = 0, tr = 0, resume = 0;
   PCONNECTION_INFO_1 p,b;
   LPTSTR lpszServer = NULL, lpszShare = NULL;

   if(argc<2)
      wprintf(L"Syntax: %s [ServerName] ShareName | \\\\ComputerName\n", argv[0]);
   else
   {
      //
      // The server is not the default local computer.
      //
      if(argc>2)
         lpszServer=argv[1];
      //
      // ShareName is always the last argument.
      //
      lpszShare=argv[argc - 1];
      //
      // Call the NetConnectionEnum function,
      //  specifying information level 1.
      //
      res=NetConnectionEnum(lpszServer, lpszShare, 1, (LPBYTE *) &p, MAX_PREFERRED_LENGTH, &er, &tr, &resume);
      //
      // If no error occurred,
      //
      if(res == 0)
      {
         //
         // If there were any results,
         //
         if(er>0)
         {
            b=p;
            //
            // Loop through the entries; print user name and network name.
            //
            for(i=0;i<er;i++)
            {
               printf("%S\t%S\n", b->coni1_username,b->coni1_netname);
               b++;
            }
            // Free the allocated buffer.
            //
            NetApiBufferFree(p);
         }
         // Otherwise, print a message depending on whether
         //  the qualifier parameter was a computer (\\ComputerName)
         //  or a share (ShareName).
         //
         else
         {
            if(lpszShare[0]=='\\')
               printf("No connection to %S from %S\n",
                  (lpszServer == NULL)?TEXT("LocalMachine"):lpszServer, lpszShare);
            else
               printf("No one connected to %S\\%S\n",
                  (lpszServer == NULL)?TEXT("\\\\LocalMachine"):lpszServer,lpszShare);
         }
      }
      //
      // Otherwise, print the error.
      //
      else
         printf("Error: %d\n",res);
   }
   return;
}

```

## See also

[CONNECTION_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-connection_info_0)

[CONNECTION_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-connection_info_1)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Share Functions](https://learn.microsoft.com/windows/desktop/NetShare/network-share-functions)