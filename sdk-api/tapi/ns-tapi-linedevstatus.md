# LINEDEVSTATUS structure

## Description

The
**LINEDEVSTATUS** structure describes the current status of a line device. The
[lineGetLineDevStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetlinedevstatus) function and the
[TSPI_lineGetLineDevStatus](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetlinedevstatus) function return the
**LINEDEVSTATUS** structure.

## Members

### `dwTotalSize`

Total size allocated to this data structure, in bytes.

### `dwNeededSize`

Size for this data structure that is needed to hold all the returned information, in bytes.

### `dwUsedSize`

Size of the portion of this data structure that contains useful information, in bytes.

### `dwNumOpens`

Number of active opens on the line device.

### `dwOpenMediaModes`

Bit array that indicates for which media types the line device is currently open.

### `dwNumActiveCalls`

Number of calls on the line in call states other than *idle*, *onhold*, *onholdpendingtransfer*, and *onholdpendingconference*.

### `dwNumOnHoldCalls`

Number of calls on the line in the *onhold* state.

### `dwNumOnHoldPendCalls`

Number of calls on the line in the *onholdpendingtransfer* or *onholdpendingconference* state.

### `dwLineFeatures`

Line-related functions that are currently available on this line. This member uses one or more of the
[LINEFEATURE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linefeature--constants).

### `dwNumCallCompletions`

Number of outstanding call completion requests on the line.

### `dwRingMode`

Current ring mode on the line device.

### `dwSignalLevel`

Current signal level of the connection on the line. This is a value in the range 0x00000000 (weakest signal) to 0x0000FFFF (strongest signal).

### `dwBatteryLevel`

Current battery level of the line device hardware. This is a value in the range 0x00000000 (battery empty) to 0x0000FFFF (battery full).

### `dwRoamMode`

Current roam mode of the line device. This member uses one of the
[LINEROAMMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/lineroammode--constants).

### `dwDevStatusFlags`

Flags that indicate status information, such as whether the device is locked. It consists of one or more members of
[LINEDEVSTATUSFLAGS_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linedevstatusflags--constants).

### `dwTerminalModesSize`

Size of the variably-sized device field containing an array of current terminal modes, in bytes.

### `dwTerminalModesOffset`

Offset from the beginning of the structure to an array of current terminal modes, in bytes. This array is indexed by terminal IDs, in the range from zero to **dwNumTerminals** minus one. Each entry in the array specifies the current terminal modes for the corresponding terminal set using the
[lineSetTerminal](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetterminal) function for this line. Each entry is a **DWORD** that specifies one or more of the
[LINETERMMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linetermmode--constants). The size of the array is specified by **dwTerminalModesSize**.

### `dwDevSpecificSize`

Size of the variably sized device-specific field, in bytes. If the device-specific information is a pointer to a string, the size must include the **null** terminator.

### `dwDevSpecificOffset`

Offset from the beginning of the structure to the device-specific field, in bytes. The size of the field is specified by **dwDevSpecificSize**.

### `dwAvailableMediaModes`

Indicates the media types that can be invoked on new calls created on this line device, when the **dwLineFeatures** member indicates that new calls are possible. If this member is zero, it indicates that the service provider either does not know or cannot indicate which media types are available, in which case any or all of the media types indicated in the **dwMediaModes** member in
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps) may be available.

### `dwAppInfoSize`

Size of the array that identifies the applications that have the line open, in bytes.

### `dwAppInfoOffset`

Offset from the beginning of the structure to an array of
[LINEAPPINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineappinfo) structures. The **dwNumOpens** member indicates the number of elements in the array. Each element in the array identifies an application that has the line open. The size of the array is specified by **dwAppInfoSize**.

## Remarks

Device-specific extensions should use the DevSpecific (**dwDevSpecificSize** and **dwDevSpecificOffset**) variably sized area of this data structure.

The members **dwAvailableMediaModes** through **dwAppInfoOffset** are available only to applications that open the line device with an API version of 2.0 or later.

## See also

[LINEAPPINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineappinfo)

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[TSPI_lineGetLineDevStatus](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetlinedevstatus)

[lineGetLineDevStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetlinedevstatus)

[lineSetTerminal](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetterminal)