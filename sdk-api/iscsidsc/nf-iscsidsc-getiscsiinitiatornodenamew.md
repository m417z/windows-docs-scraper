# GetIScsiInitiatorNodeNameW function

## Description

The **GetIscsiInitiatorNodeName** function retrieves the common initiator node name that is used when establishing sessions from the local machine.

## Parameters

### `InitiatorNodeName`

A caller-allocated buffer that, on output, receives the node name. The buffer must be large enough to hold **MAX_ISCSI_NAME_LEN+1** bytes.

## Return value

Returns ERROR_SUCCESS if the operation succeeds and the appropriate Win32 or iSCSI error code if the operation fails.

## Remarks

All initiator Host Bus Adapters, both software and hardware, use the same node name when establishing sessions.

> [!NOTE]
> The iscsidsc.h header defines GetIScsiInitiatorNodeName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).