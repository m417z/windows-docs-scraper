# NetQueryDisplayInformation function

## Description

The
**NetQueryDisplayInformation** function returns user account, computer, or group account information. Call this function to quickly enumerate account information for display in user interfaces.

## Parameters

### `ServerName` [in]

Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `Level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **1** | Return user account information. The *SortedBuffer* parameter points to an array of [NET_DISPLAY_USER](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-net_display_user) structures. |
| **2** | Return individual computer information. The *SortedBuffer* parameter points to an array of [NET_DISPLAY_MACHINE](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-net_display_machine) structures. |
| **3** | Return group account information. The *SortedBuffer* parameter points to an array of [NET_DISPLAY_GROUP](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-net_display_group) structures. |

### `Index` [in]

Specifies the index of the first entry for which to retrieve information. Specify zero to retrieve account information beginning with the first display information entry. For more information, see the following Remarks section.

### `EntriesRequested` [in]

Specifies the maximum number of entries for which to retrieve information. On Windows 2000 and later, each call to
**NetQueryDisplayInformation** returns a maximum of 100 objects.

### `PreferredMaximumLength` [in]

Specifies the preferred maximum size, in bytes, of the system-allocated buffer returned in the *SortedBuffer* parameter. It is recommended that you set this parameter to MAX_PREFERRED_LENGTH.

### `ReturnedEntryCount` [out]

Pointer to a value that receives the number of entries in the buffer returned in the *SortedBuffer* parameter. If this parameter is zero, there are no entries with an index as large as that specified. Entries may be returned when the function's return value is either NERR_Success or ERROR_MORE_DATA.

### `SortedBuffer` [out]

Pointer to a buffer that receives a pointer to a system-allocated buffer that specifies a sorted list of the requested information. The format of this data depends on the value of the *Level* parameter. Because this buffer is allocated by the system, it must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function. Note that you must free the buffer even if the function fails with ERROR_MORE_DATA. For more information, see the following Return Values section, and the topics
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_INVALID_LEVEL** | The *Level* parameter specifies an invalid value. |
| **ERROR_MORE_DATA** | More entries are available. That is, the last entry returned in the *SortedBuffer* parameter is not the last entry available. To retrieve additional entries, call **NetQueryDisplayInformation** again with the *Index* parameter set to the value returned in the **next_index** member of the last entry in *SortedBuffer*. Note that you should not use the value of the **next_index** member for any purpose except to retrieve more data with additional calls to **NetQueryDisplayInformation**. |

## Remarks

If you call this function on a domain controller that is running Active Directory, access is allowed or denied based on the access control list (ACL) for the [securable object](https://learn.microsoft.com/windows/desktop/SecAuthZ/securable-objects). The default ACL permits all authenticated users and members of the "[Pre-Windows 2000 compatible access](https://learn.microsoft.com/windows/desktop/SecAuthZ/allowing-anonymous-access)" group to view the information. If you call this function on a member server or workstation, all authenticated users can view the information. For information about anonymous access and restricting anonymous access on these platforms, see
[Security Requirements for the Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/security-requirements-for-the-network-management-functions). For more information on ACLs, ACEs, and access tokens, see
[Access Control Model](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-model).

The **NetQueryDisplayInformation** function only returns information to which the caller has Read access. The caller must have List Contents access to the Domain object, and Enumerate Entire SAM Domain access on the SAM Server object located in the System container.

The
**NetQueryDisplayInformation** and
[NetGetDisplayInformationIndex](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgetdisplayinformationindex) functions provide an efficient mechanism for enumerating user and group accounts. When possible, use these functions instead of the
[NetUserEnum](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuserenum) function or the
[NetGroupEnum](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupenum) function.

To enumerate trusting domains or member computer accounts, call
[NetUserEnum](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuserenum), specifying the appropriate filter value to obtain the account information you require. To enumerate trusted domains, call the
[LsaEnumerateTrustedDomains](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaenumeratetrusteddomains) or [LsaEnumerateTrustedDomainsEx](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaenumeratetrusteddomainsex) function.

The number of entries returned by this function depends on the security descriptor located on the root domain object. The API will return either the first 100 entries or the entire set of entries in the domain, depending on the access privileges of the user. The ACE used to control this behavior is "SAM-Enumerate-Entire-Domain", and is granted to Authenticated Users by default. Administrators can modify this setting to allow users to enumerate the entire domain.

Each call to
**NetQueryDisplayInformation** returns a maximum of 100 objects. Calling the
**NetQueryDisplayInformation** function to enumerate domain account information can be costly in terms of performance. If you are programming for Active Directory, you may be able to use methods on the
[IDirectorySearch](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-idirectorysearch) interface to make paged queries against the domain. For more information, see
[IDirectorySearch::SetSearchPreference](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-setsearchpreference) and
[IDirectorySearch::ExecuteSearch](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-executesearch). To enumerate trusted domains, call the
[LsaEnumerateTrustedDomainsEx](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaenumeratetrusteddomainsex) function.

#### Examples

The following code sample demonstrates how to return group account information using a call to the
**NetQueryDisplayInformation** function. If the user specifies a server name, the sample first calls the
[MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar) function to convert the name to Unicode. The sample calls
**NetQueryDisplayInformation**, specifying information level 3 ([NET_DISPLAY_GROUP](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-net_display_group)) to retrieve group account information. If there are entries to return, the sample returns the data and prints the group information. Finally, the code sample frees the memory allocated for the information buffer.

```cpp
#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <stdio.h>
#include <lm.h>

#pragma comment(lib, "netapi32.lib")

void main( int argc, char *argv[ ] )
{
   PNET_DISPLAY_GROUP pBuff, p;
   DWORD res, dwRec, i = 0;
   //
   // You can pass a NULL or empty string
   //  to retrieve the local information.
   //
   TCHAR szServer[255]=TEXT("");

   if(argc > 1)
      //
      // Check to see if a server name was passed;
      //  if so, convert it to Unicode.
      //
      MultiByteToWideChar(CP_ACP, 0, argv[1], -1, szServer, 255);

   do // begin do
   {
      //
      // Call the NetQueryDisplayInformation function;
      //   specify information level 3 (group account information).
      //
      res = NetQueryDisplayInformation(szServer, 3, i, 1000, MAX_PREFERRED_LENGTH, &dwRec, (PVOID*) &pBuff);
      //
      // If the call succeeds,
      //
      if((res==ERROR_SUCCESS) || (res==ERROR_MORE_DATA))
      {
         p = pBuff;
         for(;dwRec>0;dwRec--)
         {
            //
            // Print the retrieved group information.
            //
            printf("Name:      %S\n"
                  "Comment:   %S\n"
                  "Group ID:  %u\n"
                  "Attributes: %u\n"
                  "--------------------------------\n",
                  p->grpi3_name,
                  p->grpi3_comment,
                  p->grpi3_group_id,
                  p->grpi3_attributes);
            //
            // If there is more data, set the index.
            //
            i = p->grpi3_next_index;
            p++;
         }
         //
         // Free the allocated memory.
         //
         NetApiBufferFree(pBuff);
      }
      else
         printf("Error: %u\n", res);
   //
   // Continue while there is more data.
   //
   } while (res==ERROR_MORE_DATA); // end do
   return;
}

```

## See also

[Get Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/get-functions)

[LsaEnumerateTrustedDomains](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaenumeratetrusteddomains)

[LsaEnumerateTrustedDomainsEx](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaenumeratetrusteddomainsex)

[NET_DISPLAY_GROUP](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-net_display_group)

[NET_DISPLAY_MACHINE](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-net_display_machine)

[NET_DISPLAY_USER](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-net_display_user)

[NetGetDisplayInformationIndex](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgetdisplayinformationindex)

[NetGroupEnum](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupenum)

[NetUserEnum](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuserenum)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)