# FwpmGetAppIdFromFileName0 function

## Description

The **FwpmGetAppIdFromFileName0**  function retrieves an application identifier from a file name.

## Parameters

### `fileName` [in]

Type: **const wchar_t***

File name from which the application identifier will be retrieved.

### `appId` [out]

Type: [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob)**

The retrieved application identifier.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The application identifier was retrieved successfully. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

The caller must free the returned object by a call to [FwpmFreeMemory0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmfreememory0).

**FwpmGetAppIdFromFileName0**  is a specific implementation of FwpmGetAppIdFromFileName. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

#### Examples

The following C++ example shows how to retrieve an application identifier using **FwpmGetAppIdFromFileName0**.

```cpp
#include <windows.h>
#include <fwpmu.h>
#include <stdio.h>

#pragma comment(lib, "Fwpuclnt.lib")

// Hard-coded file name for demonstration purposes.
#define FILE_PATH1 L"C:\\Program Files\\SomeAppFolder\\SomeApplication.exe"

int main()
{
    DWORD  result = ERROR_SUCCESS;

    FWP_BYTE_BLOB *fwpApplicationByteBlob = NULL;

    printf("Retrieving Id for application to allow through firewall.\n");
    result = FwpmGetAppIdFromFileName0(FILE_PATH1, &fwpApplicationByteBlob);

    if (result != ERROR_SUCCESS)
    {
        printf("FwpmGetAppIdFromFileName failed (%d).\n", result);
        return result;
    }
    else
    {
        printf("The Id is: %d\n", fwpApplicationByteBlob->data);
    }

    return 0;
}
// ----------------------------------------------------------------------

```

## See also

[FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob)