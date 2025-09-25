# ComponentHangMonitorInfo structure

## Description

Represents the hang monitoring configuration for a COM+ component.

## Members

### `IsMonitored`

Indicates whether the component is configured for hang monitoring.

### `TerminateOnHang`

Indicates whether the hang monitoring configuration for the component specifies the process will be terminated on a hang. This member is meaningful only if **IsMonitored** is **TRUE**.

### `AvgCallThresholdInMs`

The average call response time threshold configured for the component. This member is meaningful only if **IsMonitored** is **TRUE**.

## See also

[IGetAppTrackerData](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-igetapptrackerdata)