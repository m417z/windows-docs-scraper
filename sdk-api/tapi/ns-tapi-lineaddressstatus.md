# LINEADDRESSSTATUS structure

## Description

The
**LINEADDRESSSTATUS** structure describes the current status of an address. The
[lineGetAddressStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetaddressstatus) function and the
[TSPI_lineGetAddressStatus](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetaddressstatus) function return the
**LINEADDRESSSTATUS** structure.

## Members

### `dwTotalSize`

Total size allocated to this data structure, in bytes.

### `dwNeededSize`

Size for this data structure that is needed to hold all the returned information, in bytes.

### `dwUsedSize`

Size of the portion of this data structure that contains useful information, in bytes.

### `dwNumInUse`

Number of stations that are currently using the address.

### `dwNumActiveCalls`

Number of calls on the address that are in call states other than *idle*, *onhold*, *onholdpendingtransfer*, and *onholdpendingconference*.

### `dwNumOnHoldCalls`

Number of calls on the address in the *onhold* state.

### `dwNumOnHoldPendCalls`

Number of calls on the address in the *onholdpendingtransfer* or *onholdpendingconference* state.

### `dwAddressFeatures`

Address-related functions that can be invoked on the address in its current state. This member uses one or more of the
[LINEADDRFEATURE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineaddrfeature--constants).

### `dwNumRingsNoAnswer`

Number of rings set for this address before an unanswered call is considered as no answer.

### `dwForwardNumEntries`

Number of entries in the array referred to by **dwForwardSize** and **dwForwardOffset**.

### `dwForwardSize`

Size of the forwarding information array, in bytes.

### `dwForwardOffset`

Offset from the beginning of the structure to the variably sized field that describes the address's forwarding information. This information is an array of **dwForwardNumEntries** elements, of type
[LINEFORWARD](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineforward). The offsets of the addresses in the array are relative to the beginning of the
**LINEADDRESSSTATUS** structure. The offsets **dwCallerAddressOffset** and **dwDestAddressOffset** in the variably sized field of type
**LINEFORWARD** pointed to by *dwForwardOffset* are relative to the beginning of the
**LINEADDRESSSTATUS** data structure (the "root" container). The size of the array is specified by **dwForwardSize**.

### `dwTerminalModesSize`

Size of the terminal modes array, in bytes.

### `dwTerminalModesOffset`

Offset from the beginning of the structure to the variably sized device field containing an array with **DWORD**-sized entries, that use one or more of the
[LINETERMMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linetermmode--constants). This array is indexed by terminal identifiers, in the range from zero to one less than **dwNumTerminals**. Each entry in the array specifies the current terminal modes for the corresponding terminal set with the
[lineSetTerminal](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetterminal) function for this address. The size of the array is specified by **dwTerminalModesSize**.

### `dwDevSpecificSize`

Size of the device-specific field, in bytes.

### `dwDevSpecificOffset`

Offset from the beginning of this structure to the variably sized device-specific field. The size of the field is specified by **dwDevSpecificSize**.

## Remarks

Device-specific extensions should use the DevSpecific (**dwDevSpecificSize** and **dwDevSpecificOffset**) variably sized area of this data structure.

This data structure is returned by the
[lineGetAddressStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetaddressstatus) function. When items in this data structure change as a consequence of activities on the address, a
[LINE_ADDRESSSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-addressstate) message is sent to the application. A parameter to this message is the address state, one of the
[LINEADDRESSSTATE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineaddressstate--constants), which indicates that the status item in this record changed.

## See also

[LINEFORWARD](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineforward)

[LINE_ADDRESSSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-addressstate)

[TSPI_lineGetAddressStatus](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetaddressstatus)

[lineGetAddressStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetaddressstatus)

[lineSetTerminal](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetterminal)