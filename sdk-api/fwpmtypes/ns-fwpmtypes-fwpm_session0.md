# FWPM_SESSION0 structure

## Description

The **FWPM_SESSION0** structure stores the state associated with a client session.

## Members

### `sessionKey`

Uniquely identifies the session.

If this member is zero in the
call to [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0), Base Filtering Engine (BFE) will generate a GUID.

### `displayData`

Allows sessions to be annotated in a human-readable form.

See [FWPM_DISPLAY_DATA0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwpm_display_data0) for more information.

### `flags`

Settings to control session behavior.

| Session flag | Meaning |
| --- | --- |
| **FWPM_SESSION_FLAG_DYNAMIC** | When this flag is set, any objects added during the session are automatically deleted when the session ends. |
| **FWPM_SESSION_FLAG_RESERVED** | Reserved. |

### `txnWaitTimeoutInMSec`

Time in milli-seconds that a client will wait to begin a transaction.

If this member is zero, BFE will use a
default timeout.

### `processId`

Process ID of the client.

### `sid`

SID of the client.

### `username`

User name of the client.

### `kernelMode`

TRUE if this is a kernel-mode client.

## Remarks

This structure contains information supplied by the client when creating a session by calling [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0), or information retrieved from the system when enumerating sessions by calling [FwpmSessionEnum0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmsessionenum0).

The members **processId**, **sid**, **username**, and **kernelMode** are not supplied by the client. They are supplied by BFE and can be retrieved when enumerating sessions.

**FWPM_SESSION0** is a specific implementation of FWPM_SESSION. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_DISPLAY_DATA0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwpm_display_data0)

[FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0)

[FwpmSessionEnum0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmsessionenum0)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)