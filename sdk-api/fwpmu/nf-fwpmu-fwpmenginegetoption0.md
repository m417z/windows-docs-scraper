# FwpmEngineGetOption0 function

## Description

The **FwpmEngineGetOption0** function retrieves a filter engine option.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `option` [in]

Type: [FWPM_ENGINE_OPTION](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ne-fwpmtypes-fwpm_engine_option)

The option to be retrieved.

### `value` [out]

Type: [FWP_VALUE0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_value0)**

The option value. The data type contained in the *value* parameter will be **FWP_UINT32**.

If *option* is **FWPM_ENGINE_COLLECT_NET_EVENTS**, *value* will be one of the following.

| Value | Meaning |
| --- | --- |
| 0 | Network events are not being collected. |
| 1 | Network events are being collected. |

If *option* is **FWPM_ENGINE_NET_EVENT_MATCH_ANY_KEYWORDS**, *value* will be a bitwise combination of the following values.

| Value | Meaning |
| --- | --- |
| **FWPM_NET_EVENT_KEYWORD_INBOUND_MCAST**<br><br>1 | Inbound multicast network events are being collected. |
| **FWPM_NET_EVENT_KEYWORD_INBOUND_BCAST**<br><br>2 | Inbound broadcast network events are not being collected. |

If *option* is **FWPM_ENGINE_PACKET_QUEUING** (available only in Windows 8 and Windows Server 2012), *value* will be one of the following.

| Value | Meaning |
| --- | --- |
| **FWPM_ENGINE_OPTION_PACKET_QUEUE_NONE**<br><br>0 | No packet queuing is enabled. |
| **FWPM_ENGINE_OPTION_PACKET_QUEUE_INBOUND**<br><br>1 | Inbound packet queuing is enabled. |
| **FWPM_ENGINE_OPTION_PACKET_QUEUE_OUTBOUND**<br><br>2 | Outbound packet queuing is enabled. |

If *option* is **FWPM_ENGINE_MONITOR_IPSEC_CONNECTIONS** (available only in Windows 8 and Windows Server 2012), *value* will be one of the following.

| Value | Meaning |
| --- | --- |
| 0 | The IPsec Connection Monitoring feature is disabled. No IPsec connection events or notifications are being logged. |
| 1 | The IPsec Connection Monitoring feature is enabled. New IPsec connection events and notifications are being logged. |

If *option* is **FWPM_ENGINE_TXN_WATCHDOG_TIMEOUT_IN_MSEC** (available only in Windows 8 and Windows Server 2012), *value* will be the time in milliseconds that specifies the maximum duration for a single WFP transaction. Transactions taking longer than this duration will trigger a watchdog event.

The **FWPM_ENGINE_NAME_CACHE** option is reserved for internal use.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The option was retrieved successfully. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

The caller must free the returned object by a call to [FwpmFreeMemory0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmfreememory0).

The caller needs [FWPM_ACTRL_READ](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the filter engine. See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

**FwpmEngineGetOption0** is a specific implementation of FwpmEngineGetOption. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

#### Examples

The following C++ example illustrates the use of **FwpmEngineGetOption0** to determine if network events are being collected.

```cpp
#include <windows.h>
#include <fwpmu.h>
#include <stdio.h>

#pragma comment(lib, "Fwpuclnt.lib")

void main()
{
    HANDLE engineHandle = NULL;
    DWORD  result = ERROR_SUCCESS;

    FWPM_ENGINE_OPTION option = FWPM_ENGINE_COLLECT_NET_EVENTS;
    FWP_VALUE0* fwpValue = NULL;

    result = FwpmEngineOpen0( NULL, RPC_C_AUTHN_WINNT, NULL, NULL, &engineHandle );
    if (result != ERROR_SUCCESS)
    {
        printf("FwpmEngineOpen0 failed.\n");
        return;
    }

    result = FwpmEngineGetOption0( engineHandle, option, &fwpValue);

    if (result != ERROR_SUCCESS)
    {
        printf("FwpmEngineGetOption0 failed.\n");
        return;
    }
    else if(fwpValue->type == FWP_UINT32)
    {
        if(fwpValue->uint32 == 1 )
            printf("Network events are being collected.\n");
        else
            printf("Network events are NOT being collected.\n");
    }
    else
        printf("Unexpected data type received.\n");

    FwpmFreeMemory0((void**)&fwpValue);

    return;
}

```

## See also

[FWPM_ENGINE_OPTION](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ne-fwpmtypes-fwpm_engine_option)

[FWP_VALUE0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_value0)

[FwpmEngineSetOption0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmenginesetoption0)