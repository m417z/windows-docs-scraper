# GROUP_FAILURE_INFO structure

## Description

Represents information about the [Failover](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/failover) attempts for a group failure.

## Members

### `dwFailoverAttemptsRemaining`

The number of remaining failover attempts that can be made on the group during the current [FailoverPeriod](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups-failoverperiod) time interval.

### `dwFailoverPeriodRemaining`

The amount of time remaining for the [FailoverPeriod](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups-failoverperiod), in hours.

## See also

[Utility structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/utility-structures)