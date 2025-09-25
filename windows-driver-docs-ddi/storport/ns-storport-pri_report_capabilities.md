## Description

The **PRI_REPORT_CAPABILITIES** structure contains the information on persistent reservation features that is returned in response to a Persistent Reserve In command with `ServiceAction=RESERVATION_ACTION_REPORT_CAPABILITIES`.

## Members

### `Length[2]`

The size of this structure.

### `PersistThroughPowerLossCapable`

Indicates that the device server supports persisting through a power loss event.

### `Reserved`

Reserved for internal use.

### `AllTargetPortsCapable`

Indicates that the device server supports all target ports.

### `SpecifyInitiatorPortsCapable`

Indicates that the device server supports specifying initiator ports.

### `CompatibleReservationHandling`

Indicates that the device server is backward compatible with SPC-2.

### `Reserved1`

Reserved for internal use.

### `ReplaceLostReservationCapable`

Indicates that the device server supports replacing a lost reservation.

### `PersistThroughPowerLossActivated`

Indicates that the persist through power loss capability is activated.

### `Reserved2`

Reserved for internal use.

### `AllowCommands`

Indicates whether certain commands are allowed through certain types of persistent reservations.

| Value | Description |
|--|--|
| 0 | No information is provided about whether certain commands are allowed through certain types of persistent reservations. |
| 1 | The device server allows the TEST UNIT READY command through write exclusive type reservations and exclusive access type reservations. The device server does not provide information about whether the following commands are allowed through Write Exclusive type reservations:

1. MODE SENSE
2. READ ATTRIBUTE
3. READ BUFFER(10)
4. RECEIVE DIAGNOSTIC RESULTS
5. REPORT SUPPORTED OPERATION CODES
6. REPORT SUPPORTED TASK MANAGEMENT FUNCTIONS
7. READ DEFECT DATA

|
| 2 | The device server allows the TEST UNIT READY command through write exclusive type reservations and exclusive access type reservations. The device server does not allow the following commands through Write Exclusive type reservations:

1. MODE SENSE
2. READ ATTRIBUTE
3. READ BUFFER(10)
4. RECEIVE DIAGNOSTIC RESULTS
5. REPORT SUPPORTED OPERATION CODES
6. REPORT SUPPORTED TASK MANAGEMENT FUNCTIONS
7. READ DEFECT DATA

|
| 3 | The device server allows the TEST UNIT READY command through write exclusive and exclusive access type reservations. And the following commands through write exclusive type reservations:

1. MODE SENSE
2. READ ATTRIBUTE
3. READ BUFFER(10)
4. RECEIVE DIAGNOSTIC RESULTS
5. REPORT SUPPORTED OPERATION CODES
6. REPORT SUPPORTED TASK MANAGEMENT FUNCTIONS
7. READ DEFECT DATA

|
| 4 | The device server allows the TEST UNIT READY command through write exclusive and exclusive access persistent reservations. And the following commands through write exclusive persist reservations:

1. MODE SENSE
2. READ ATTRIBUTE
3. READ BUFFER(10)
4. RECEIVE DIAGNOSTIC RESULTS
5. REPORT SUPPORTED OPERATION CODES
6. REPORT SUPPORTED TASK MANAGEMENT FUNCTIONS
7. READ DEFECT DATA

|
| 5 | The device server allows:

1. The following commands through write exclusive and exclusive access persistent reservations:
   1. TEST UNIT READY
   2. REPORT SUPPORTED OPERATION CODES
   3. REPORT SUPPORTED TASK MANAGEMENT FUNCTIONS
2. The following commands through write exclusive persistent reservations:
   1. MODE SENSE
   2. READ ATTRIBUTE
   3. READ BUFFER(10)
   4. RECEIVE DIAGNOSTIC RESULTS
   5. READ DEFECT DATA

|
| All others | Reserved |

### `TypeMaskValid`

Contains a bitmask that indicates the persistent reservation types that are supported by the device server.

### `Reserved3`

Reserved for internal use.

### `WriteExclusive`

Indicates that the device server supports the write exclusive persistent reservation type.

### `Reserved4`

Reserved for internal use.

### `ExclusiveAccess`

Indicates that the device server supports the exclusive access persistent reservation type.

### `Reserved5`

Reserved for internal use.

### `WriteExclusiveRegistrantsOnly`

Indicates that the device server supports the write exclusive – registrants only persistent reservation type.

### `ExclusiveAccessRegistrantsOnly`

Indicates that the device server supports the exclusive access – registrants only persistent reservation type.

### `WriteExclusiveAllRegistrants`

Indicates that the device server supports the write exclusive – all registrants persistent reservation type.

### `ExclusiveAccessAllRegistrants`

Indicates that the device server supports the exclusive access – all registrants persistent reservation type.

### `Reserved6`

Reserved for internal use.

### `Reserved7[2]`

Reserved for internal use.

## Remarks

## See also