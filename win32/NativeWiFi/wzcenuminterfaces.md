# WZCEnumInterfaces function

\[**WZCEnumInterfaces** is no longer supported as of Windows Vista and Windows Server 2008. Instead, use the [**WlanEnumInterfaces**](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanenuminterfaces) function. For more information, see [About the Native Wifi API](https://learn.microsoft.com/windows/win32/nativewifi/about-the-native-wifi-api).\]

The **WZCEnumInterfaces** function enumerates all of the wireless LAN interfaces managed by the Wireless Zero Configuration service.

## Parameters

*pSrvAddr* \[in\]

A pointer to a string containing the name of the computer on which to execute this function. If this parameter is **NULL**, then the Wireless Zero Configuration service is enumerated on the local computer.

If the *pSrvAddr* parameter specified is a remote computer, then the remote computer must support remote RPC calls.

*pIntfs* \[out\]

A pointer to a [**INTFS\_KEY\_TABLE**](https://learn.microsoft.com/windows/win32/nativewifi/intfs-key-table) structure that contains a table of key information for all interfaces.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
|-----------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **ERROR\_ARENA\_TRASHED** | The storage control blocks were destroyed. This error is returned if the Wireless Zero Configuration service has not initialized internal objects.<br> |
| **RPC\_S\_UNKNOWN\_IF** | The interface is unknown.<br> This error is returned if the Wireless Zero Configuration service is not started.<br> |
| **RPC\_X\_NULL\_REF\_POINTER** | A null reference pointer was passed to the stub.<br> This error is returned if the *pIntfs* parameter is **NULL**.<br> |
| **ERROR\_NOT\_ENOUGH\_MEMORY** | Not enough memory is available to process this request and allocate memory for the query results.<br> |
| **RPC\_STATUS** | Various error codes.<br> |

## Remarks

The **dwNumIntfs** member of the [**INTFS\_KEY\_TABLE**](https://learn.microsoft.com/windows/win32/nativewifi/intfs-key-table) structure pointed to by *pIntf* must be set to 0 before calling the **WZCEnumInterfaces** function. Also, the **pIntfs** member must be set to **NULL**.

For subsequent calls to other Wireless Zero Configuration functions, an application must identify the interface it is operating on by providing relevant key information returned by the **WZCEnumInterfaces** function.

If the **WZCEnumInterfaces** returns ERROR\_SUCCESS, the caller should call [**LocalFree**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-localfree) to release the internal buffers allocated for the data returned once this information is no longer needed.

> [!Note]
> The *Wzcsapi.h* header file and *Wzcsapi.lib* import library file are not available in the Windows SDK.

## Examples

The following example enumerates the wireless LAN interfaces on the local computer managed by the Wireless Zero Configuration service and prints out the value for interface GUID for each interface.

> [!Note]
> This example will fail on Windows Vista and later .

```C++
#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <objbase.h>
#include <wtypes.h>

#include <stdio.h>
#include <stdlib.h>

// Wzcsapi.h and Wsczapi.lib were never shipped
// So we need to LOadlibrary and call the WZCEnumInterfaces function
// in Wzcsapi.dll in the

typedef struct
{
    LPWSTR wszGuid;
} INTF_KEY_ENTRY, *PINTF_KEY_ENTRY;

typedef struct
{
    DWORD dwNumIntfs;
    PINTF_KEY_ENTRY pIntfs;
} INTFS_KEY_TABLE, *PINTFS_KEY_TABLE;

DWORD WZCEnumInterfaces(LPWSTR pSrvAddr, PINTFS_KEY_TABLE pIntfs);

//Define the function prototype
typedef DWORD (CALLBACK* WZCEnumInterfacesType)(LPWSTR, PINTFS_KEY_TABLE);

int wmain()
{
    // Declare and initialize variables.

    DWORD dwResult = 0;
//    int iRet = 0;

//    WCHAR GuidString[40] = {0};

    int i;

    /* variables used for WZCEnumInterfaces  */

    PINTFS_KEY_TABLE pIfList;
    PINTF_KEY_ENTRY pIfInfo;

    BOOL freeResult = FALSE;
    BOOL runTimeLinkSuccess = FALSE;
    HINSTANCE dllHandle = NULL;
    WZCEnumInterfacesType WZCEnumInterfacesPtr = NULL;

//    wprintf(L"Sample to test WZCEnumInterface\n");

    //Load the dll and keep the handle to it
    dllHandle = LoadLibrary( (LPCWSTR) L"wzcsapi.dll");

    // If the handle is valid, try to get the function address.
    if (dllHandle == NULL) {
        dwResult = GetLastError();
        wprintf(L"LoadLibrary of wzcsapi.dll failed with error: %d\n", dwResult);
        if (dwResult ==  ERROR_MOD_NOT_FOUND)
            wprintf(L"Error: The specified module could not be found\n");
        return 1;
    }
    else
    {
        //Get pointer to our function using GetProcAddress:
        WZCEnumInterfacesPtr = (WZCEnumInterfacesType) GetProcAddress(dllHandle,
         "WZCEnumInterfaces");

        if (WZCEnumInterfacesPtr != NULL)
            runTimeLinkSuccess = TRUE;
        else {
            dwResult = GetLastError();
            wprintf(L"GetProcAddress of WZCEnumInterfaces failed with error: %d\n", dwResult);
            return 1;
        }

        // The function address is valid, allocate some memory for pIflist
        pIfList = (PINTFS_KEY_TABLE) LocalAlloc(LMEM_ZEROINIT,4096);
        if (pIfList == NULL) {
            wprintf(L"Unable to allocate memory to store INTFS_KEY_TABLE\n");
            freeResult = FreeLibrary(dllHandle);
            return 1;
        }

        // If the function address is valid, call the function.
        if (runTimeLinkSuccess)
        {
            dwResult = WZCEnumInterfacesPtr(NULL, pIfList);
            if (dwResult != ERROR_SUCCESS)  {
                wprintf(L"WZCEnumInterfaces failed with error: %u\n", dwResult);
                // FormatMessage can be used to find out why the function failed
                  //Free the library:
                freeResult = FreeLibrary(dllHandle);
                return 1;
            }
            else {
                wprintf(L"Num Entries: %lu\n", pIfList->dwNumIntfs);

                for (i = 0; i < (int) pIfList->dwNumIntfs; i++) {
                    pIfInfo = &pIfList->pIntfs[i];
                    if (pIfInfo->wszGuid == NULL)
                        wprintf(L"  InterfaceGUID[%d]: NULL\n",i);
                    else
                        wprintf(L"  InterfaceGUID[%d]: %ws\n",i, pIfInfo->wszGuid);

                }
            }
            wprintf(L"\n");
        }

        freeResult = FreeLibrary(dllHandle);
    }

    if (pIfList != NULL) {
        LocalFree(pIfList);
        pIfList = NULL;
    }
    return 0;
}
```

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP with SP2 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| End of client support<br> | Windows XP with SP3<br> |
| End of server support<br> | Windows Server 2003<br> |
| Header<br> | Wzcsapi.h |
| Library<br> | Wzcsapi.lib |
| DLL<br> | Wzcsapi.dll |

## See also

[**INTFS\_KEY\_TABLE**](https://learn.microsoft.com/windows/win32/nativewifi/intfs-key-table)

[**INTF\_KEY\_ENTRY**](https://learn.microsoft.com/windows/win32/nativewifi/intf-key-entry)

[**WZCEapolGetInterfaceParams**](https://learn.microsoft.com/windows/win32/nativewifi/wzceapolgetinterfaceparams)

[**WZCQueryInterface**](https://learn.microsoft.com/windows/win32/nativewifi/wzcqueryinterface)

[**WZCRefreshInterface**](https://learn.microsoft.com/windows/win32/nativewifi/wzcrefreshinterface)

