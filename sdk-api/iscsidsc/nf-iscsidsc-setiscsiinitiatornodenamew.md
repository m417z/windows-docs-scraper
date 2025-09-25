# SetIScsiInitiatorNodeNameW function

## Description

The **SetIscsiInitiatorNodeName** function establishes an initiator node name for the computer. This name is utilized by any initiator nodes on the computer that are communicating with other nodes.

## Parameters

### `InitiatorNodeName`

The initiator node name. If this parameter is **null**, initiators use a default initiator node name based upon the computer name.

## Return value

Returns ERROR_SUCCESS if the operation succeeds. Otherwise, it returns the appropriate Win32 or iSCSI error code.

## Remarks

The **SetIscsiInitiatorNodeName** routine does not verify that the format of the name in *InitiatorNodeName* is correct.

Some hardware initiator drivers can respond immediately to a change of the node name, while others must be restarted to finalize the change to the node name.

> [!NOTE]
> The iscsidsc.h header defines SetIScsiInitiatorNodeName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).