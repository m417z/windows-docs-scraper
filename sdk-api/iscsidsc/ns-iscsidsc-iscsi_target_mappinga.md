# ISCSI_TARGET_MAPPINGA structure

## Description

The ISCSI_TARGET_MAPPING structure contains information about a target and the Host-Bus Adapters (HBAs) and buses through which the target is reached.

## Members

### `InitiatorName`

A string representing the name of the HBA initiator through which the target is accessed.

### `TargetName`

A string representing the target name.

### `OSDeviceName`

A string representing the device name of the HBA initiator; for example '**\device\ScsiPort3**'.

### `SessionId`

A [ISCSI_UNIQUE_SESSION_ID](https://learn.microsoft.com/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_unique_session_id) structure containing information that uniquely identifies the session..

### `OSBusNumber`

The bus number used by the initiator as the local SCSI address of the target.

### `OSTargetNumber`

The target number used by the initiator as the local SCSI address of the target.

### `LUNCount`

The number of logical units (LUN) on the target.

### `LUNList`

A list of SCSI_LUN_LIST structures that contain information about the LUNs associated with the target.

### `size_is`

### `size_is.LUNCount`

## See also

[ISCSI_UNIQUE_SESSION_ID](https://learn.microsoft.com/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_unique_session_id)

## Remarks

> [!NOTE]
> The iscsidsc.h header defines ISCSI_TARGET_MAPPING as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).