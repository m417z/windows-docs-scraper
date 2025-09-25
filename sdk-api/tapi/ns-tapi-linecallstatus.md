# LINECALLSTATUS structure

## Description

The
**LINECALLSTATUS** structure describes the current status of a call. The information in this structure depends on the device capabilities of the address, the ownership of the call by the invoking application, and the current state of the call being queried. The
[lineGetCallStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcallstatus) and
[TSPI_lineGetCallStatus](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetcallstatus) functions return the
**LINECALLSTATUS** structure.

## Members

### `dwTotalSize`

Total size allocated to this data structure, in bytes.

### `dwNeededSize`

Size for this data structure that is needed to hold all the returned information, in bytes.

### `dwUsedSize`

Size of the portion of this data structure that contains useful information, in bytes.

### `dwCallState`

Current call state of the call using one of the
[LINECALLSTATE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallstate--constants).

### `dwCallStateMode`

Interpretation of the **dwCallStateMode** member is call-state-dependent. In many cases, the value will be zero. The following table shows **dwCallStateMode** types for a given **dwCallState** value.

| dwCallState | Meaning |
| --- | --- |
| **LINECALLSTATE_BUSY** | [LINEBUSYMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linebusymode--constants) |
| **LINECALLSTATE_CONNECTED** | [LINECONNECTEDMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/lineconnectedmode--constants) |
| **LINECALLSTATE_DIALTONE** | [LINEDIALTONEMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linedialtonemode--constants) |
| **LINECALLSTATE_DISCONNECTED** | [LINEDISCONNECTMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linedisconnectmode--constants) |
| **LINECALLSTATE_OFFERING** | [LINEOFFERINGMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/lineofferingmode--constants) |
| **LINECALLSTATE_SPECIALINFO** | [LINESPECIALINFO_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linespecialinfo--constants) |

### `dwCallPrivilege`

Application's privilege for this call. This member uses one or more of the
[LINECALLPRIVILEGE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallprivilege--constants).

### `dwCallFeatures`

Flags that indicate the Telephony API functions that can be invoked on the call, given the availability of the feature in the device capabilities, the current call state, and call ownership of the invoking application. A zero indicates the corresponding feature cannot be invoked by the application on the call in its current state; a one indicates the feature can be invoked. This member uses
[LINECALLFEATURE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallfeature--constants).

### `dwDevSpecificSize`

Size of the device-specific field, in bytes.

### `dwDevSpecificOffset`

Offset from the beginning of the structure to the variably sized device-specific field. The size of the field is specified by **dwDevSpecificOffset**.

### `dwCallFeatures2`

Indicates additional functions can be invoked on the call, given the availability of the feature in the device capabilities, the current call state, and call ownership of the invoking application. An extension of the **dwCallFeatures** member. This member uses
[LINECALLFEATURE2_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallfeature2--constants).

### `tStateEntryTime`

Coordinated Universal Time at which the current call state was entered.

## Remarks

Device-specific extensions should use the DevSpecific (**dwDevSpecificSize** and **dwDevSpecificOffset**) variably sized area of this data structure.

The application is sent a
[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate) message whenever the call state of a call changes. This message only provides the new call state of the call. Additional status about a call is available with
[lineGetCallStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcallstatus).

The members **dwCallFeatures2** and **tStateEntryTime** are available only to applications that open the line device with an API version of 2.0 or later.

## See also

[LINEDIALPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedialparams)

[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate)

[TSPI_lineGetCallStatus](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetcallstatus)

[lineGetCallStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcallstatus)