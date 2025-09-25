# RemoveIScsiSendTargetPortalW function

## Description

The **RemoveIscsiSendTargetPortal** function removes a portal from the list of portals to which the iSCSI initiator service sends **SendTargets** requests for target discovery.

## Parameters

### `InitiatorInstance` [in, optional]

The name of the Host Bus Adapter (HBA) that the iSCSI initiator service uses to establish a discovery session and perform **SendTargets** requests. A value of **null** indicates that the iSCSI initiator service will use any HBA that is capable of accessing the target portal.

### `InitiatorPortNumber` [in, optional]

The port number on the HBA that the iSCSI initiator service use to perform **SendTargets** requests.

### `Portal` [in]

A pointer to a structure of type [ISCSI_TARGET_PORTAL](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_target_portala) that specifies the target portal that the iSCSI initiator service removes from its list of portals.

## Return value

Returns ERROR_SUCCESS if the operation succeeds. Otherwise, it returns the appropriate Win32 or iSCSI error code.

## See also

[ISCSI_TARGET_PORTAL](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_target_portala)

## Remarks

> [!NOTE]
> The iscsidsc.h header defines RemoveIScsiSendTargetPortal as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).