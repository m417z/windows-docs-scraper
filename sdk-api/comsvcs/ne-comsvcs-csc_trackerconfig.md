# CSC_TrackerConfig enumeration

## Description

Indicates whether the tracker property is added to the context in which the enclosed code runs.

## Constants

### `CSC_DontUseTracker:0`

The tracker property is not added to the context in which the enclosed code runs.

### `CSC_UseTracker`

The tracker property is added to the context in which the enclosed code runs.

## Remarks

This enumeration is used to configure the tracker property through [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) for either the work submitted through the activity created by [CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity) or the work that is enclosed between calls to [CoEnterServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coenterservicedomain) and [CoLeaveServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coleaveservicedomain).

The tracker property is a reporting mechanism used by monitoring code to watch which code is running at a given time. It is the reporting mechanism behind the spinning balls in the Component Services administrative tool.

## See also

[CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig)

[CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity)

[CoEnterServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coenterservicedomain)

[IServiceTrackerConfig::TrackerConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iservicetrackerconfig-trackerconfig)