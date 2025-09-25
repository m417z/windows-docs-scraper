# RefreshIScsiSendTargetPortalW function

## Description

The **RefreshIscsiSendTargetPortal** function instructs the iSCSI initiator service to establish a discovery session with the indicated target portal and transmit a **SendTargets** request to refresh the list of discovered targets for the iSCSI initiator service.

## Parameters

### `InitiatorInstance` [in, optional]

The name of the Host Bus Adapter (HBA) to use for the **SendTargets** request. If **null**, the iSCSI initiator service uses any HBA that can reach the indicated target portal is chosen.

### `InitiatorPortNumber` [in]

The port number on the HBA to use for the **SendTargets** request. If the value is **ISCSI_ALL_INITIATOR_PORTS**, the initiator HBA will choose the appropriate port based upon current routing information.

### `Portal` [in]

A pointer to a structure of type [ISCSI_TARGET_PORTAL](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_target_portala) indicating the portal to which the iSCSI initiator service sends the **SendTargets** request to refresh the list of targets.

## Return value

Returns ERROR_SUCCESS if the operation succeeds. Otherwise, it returns the appropriate Win32 or iSCSI error code.

## See also

[ISCSI_TARGET_PORTAL](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_target_portala)

## Remarks

> [!NOTE]
> The iscsidsc.h header defines RefreshIScsiSendTargetPortal as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).