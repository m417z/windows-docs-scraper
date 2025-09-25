# RESOURCE_FAILURE_INFO structure

## Description

Represents information about the [Failover](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/failover) attempts for a resource. This structure is used by the [RESOURCE_FAILURE_INFO_BUFFER](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-resource_failure_info_buffer) structure.

## Members

### `dwRestartAttemptsRemaining`

The number of remaining failover attempts that can be made on the resource during the current [FailoverPeriod](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups-failoverperiod) time interval.

### `dwRestartPeriodRemaining`

The amount of time remaining for the [FailoverPeriod](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups-failoverperiod), in seconds.

## See also

[RESOURCE_FAILURE_INFO_BUFFER](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-resource_failure_info_buffer)

[Utility Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/utility-structures)