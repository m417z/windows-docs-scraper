# FwpmSubLayerAdd0 function

## Description

The **FwpmSubLayerAdd0** function adds a new sublayer to the system.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `subLayer` [in]

Type: [FWPM_SUBLAYER0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_sublayer0)*

The sublayer to be added.

### `sd` [in, optional]

Type: **[PSECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)**

Security information for the sublayer object.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The sublayer was successfully added. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

If the caller supplies a null security descriptor, the system will assign a default security descriptor.

This function cannot be called from within a read-only transaction. It will fail
with **FWP_E_INCOMPATIBLE_TXN**. See [Object Management](https://learn.microsoft.com/windows/desktop/FWP/object-management) for more information about transactions.

The caller needs [FWPM_ACTRL_ADD](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the sublayers's container and **FWPM_ACTRL_ADD_LINK** access to the provider (if any). See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

**FwpmSubLayerAdd0** is a specific implementation of FwpmSubLayerAdd. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

#### Examples

The following C++ example illustrates initialization of a sublayer object and adding the sublayer key to a filter object.

```cpp
#include <windows.h>
#include <fwpmu.h>
#include <rpc.h>
#include <stdio.h>

#pragma comment(lib, "Fwpuclnt.lib")
#pragma comment(lib, "Rpcrt4.lib")

void main()
{
    FWPM_FILTER0    fwpFilter;
    FWPM_SUBLAYER0    fwpFilterSubLayer;
    HANDLE engineHandle = NULL;
    DWORD  result = ERROR_SUCCESS;
    RPC_STATUS rpcStatus = RPC_S_OK;

    memset(&fwpFilterSubLayer, 0, sizeof(fwpFilterSubLayer));
    rpcStatus = UuidCreate(&fwpFilterSubLayer.subLayerKey);

    if (RPC_S_OK != rpcStatus)
    {
           printf("UuidCreate failed (%d).\n", rpcStatus);
           return;
    }

    result = FwpmEngineOpen0( NULL, RPC_C_AUTHN_WINNT, NULL, NULL, &engineHandle );
    if (result != ERROR_SUCCESS)
    {
        printf("FwpmEngineOpen0 failed.\n");
        return;
    }

    fwpFilterSubLayer.displayData.name = L"MyFilterSublayer";
    fwpFilterSubLayer.displayData.description = L"My filter sublayer";
    fwpFilterSubLayer.flags = 0;
    fwpFilterSubLayer.weight = 0x100;

    printf("Adding filter sublayer.\n");
      result = FwpmSubLayerAdd0(engineHandle, &fwpFilterSubLayer, NULL);

      if (result != ERROR_SUCCESS)
      {
           printf("FwpmSubLayerAdd0 failed (%d).\n", result);
           return;
    }

    // Add sublayer key to a filter.
    memset(&fwpFilter, 0, sizeof(FWPM_FILTER0));

    if (&fwpFilterSubLayer.subLayerKey != NULL)
        fwpFilter.subLayerKey = fwpFilterSubLayer.subLayerKey;

    // Finish initializing filter...

    return;
}

```

## See also

[FWPM_SUBLAYER0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_sublayer0)

[Management Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-mgmt-functions)

[WFP Functions](https://learn.microsoft.com/windows/desktop/FWP/fwp-functions)