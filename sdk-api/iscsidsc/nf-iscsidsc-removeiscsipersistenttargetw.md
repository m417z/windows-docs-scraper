# RemoveIScsiPersistentTargetW function

## Description

The **RemoveIscsiPersistentTarget** function removes a persistent login for the specified hardware initiator Host Bus Adapter (HBA), initiator port, and target portal.

## Parameters

### `InitiatorInstance` [in]

The name of the initiator that maintains the persistent login to remove.

### `InitiatorPortNumber` [in, optional]

The port number on which the initiator connects to *TargetName*. If *InitiatorPortNumber* is **ISCSI_ALL_INITIATOR_PORTS** the miniport driver for the initiator HBA removes the *TargetName* from the persistent login lists for all initiator ports.

### `TargetName` [in]

The name of the target.

### `Portal` [in]

The portal through which the initiator connects to the target. If *Portal* is **null** or contains no information, the miniport driver for the initiator HBA removes persistent logins for the target on all portals.

## Return value

Returns ERROR_SUCCESS if the operation succeeds. Otherwise, it returns the appropriate Win32 or iSCSI error code.

## See also

[AddPersistentIscsiDevice](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-addpersistentiscsidevicea)

[ClearPersistentIscsiDevices](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-clearpersistentiscsidevices)

[RemovePersistentIscsiDevice](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-removepersistentiscsidevicea)

[ReportIscsiPersistentLogins](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-reportiscsipersistentloginsa)

[ReportPersistentIscsiDevices](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-reportpersistentiscsidevicesa)

[SetupPersistentIscsiDevices](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-setuppersistentiscsidevices)

## Remarks

> [!NOTE]
> The iscsidsc.h header defines RemoveIScsiPersistentTarget as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).