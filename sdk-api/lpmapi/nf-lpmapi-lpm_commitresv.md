# LPM_CommitResv function

## Description

The
*LPM_CommitResv* function is called by the PCM to obtain reservation commitment decisions from the LPM.

## Parameters

### `RsvpSession` [in]

Pointer to the RSVP session object for which the reservation commitment is being requested.

### `FlowInstalledIntf` [in]

Pointer to the interface on which the message was received. The received interface IP address is supplied as the RSVP HOP object, and the Logical Interface Handle is set to the SNMP Index. Note that interface index numbers can change with the addition and deletion of interfaces, due to the Plug and Play features of Windows 2000.

### `RsvpStyle` [in]

RSVP reservation style being requested.

### `FilterSpecCount` [in]

Number of filter specs in *ppFilterSpecList*.

### `ppFilterSpecList` [in]

Array of filter specs, listing the senders for whom the flow is created.

### `pMergedFlowSpec` [in]

The
[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structure installed on the specified interface. The
**FLOWSPEC** structure is a merged flow for all receivers that can be reached by *FlowInstalledIntf*.

### `CommitDecision` [in]

Value of the commitment decision reached by the LPM. The following list indicates possible values:

#### RESOURCES_ALLOCATED

#### RESOURCES_MODIFIED

## Remarks

When the resources are allocated by the SBM for a new reservation, it calls LPMs with *CommitDecision* set to RESOURCES_ALLOCATED. When resources allocated for an existing reservation are changed, the SBM calls the
*LPM_CommitResv* function with *CommitDecision* set to RESOURCES_MODIFIED.

## See also

[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec)