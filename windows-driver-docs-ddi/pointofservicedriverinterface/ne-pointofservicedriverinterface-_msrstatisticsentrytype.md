# _MsrStatisticsEntryType enumeration

## Description

This enumeration defines the kinds of magnetic stripe reader statistics.

## Constants

### `MsrStatisticsEntryType_Invalid`

Reserved for internal use.

### `MsrStatisticsEntryType_HoursPoweredCount`

Number of hours that the device has been powered on.

### `MsrStatisticsEntryType_CommunicationErrorCount`

Number of communication errors.

### `MsrStatisticsEntryType_GoodReadCount`

Number of successful reads

### `MsrStatisticsEntryType_FailedReadCount`

Number of failed reads

### `MsrStatisticsEntryType_UnreadableCardCount`

Number of unreadable cards

### `MsrStatisticsEntryType_GoodWriteCount`

Number of successful writes. Do not use.

### `MsrStatisticsEntryType_FailedWriteCount`

Number of failed writes. Do not use.

### `MsrStatisticsEntryType_MissingStartSentinelTrack1Count`

Number of missing start sentinel errors on track 1. May indicate an empty track.

### `MsrStatisticsEntryType_ParityLRCErrorTrack1Count`

Number of Parity or LRC errors on track 1

### `MsrStatisticsEntryType_MissingStartSentinelTrack2Count`

Number of missing start sentinel errors on track 2. May indicate an empty track.

### `MsrStatisticsEntryType_ParityLRCErrorTrack2Count`

Number of Parity or LRC errors on track 2

### `MsrStatisticsEntryType_MissingStartSentinelTrack3Count`

Number of missing start sentinel errors on track 3. May indicate an empty track.

### `MsrStatisticsEntryType_ParityLRCErrorTrack3Count`

Number of Parity or LRC errors on track 3

### `MsrStatisticsEntryType_MissingStartSentinelTrack4Count`

Number of missing start sentinel errors on track 4. May indicate an empty track.

### `MsrStatisticsEntryType_ParityLRCErrorTrack4Count`

Number of Parity or LRC errors on track 4

### `MsrStatisticsEntryType_GoodCardAuthenticationDataCount`

Number of successful card authentication data reads

### `MsrStatisticsEntryType_FailedCardAuthenticationDataCount`

Number of failed card authentication data reads

### `MsrStatisticsEntryType_ChallengeRequestCount`

Number of successful calls to **RetrieveDeviceAuthenticationDataAsync**.

### `MsrStatisticsEntryType_GoodDeviceAuthenticationCount`

Number of successful card authentication attempts

### `MsrStatisticsEntryType_FailedDeviceAuthenticationCount`

Number of failed card authentication attempts

### `MsrStatisticsEntryType_Count`

Count of entry types