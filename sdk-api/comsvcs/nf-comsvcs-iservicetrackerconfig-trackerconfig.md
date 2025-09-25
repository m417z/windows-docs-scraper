# IServiceTrackerConfig::TrackerConfig

## Description

Configures the tracker property for the enclosed work.

## Parameters

### `trackerConfig` [in]

A value from the [CSC_TrackerConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_trackerconfig) enumeration.

### `szTrackerAppName` [in]

The application identifier under which tracker information is reported.

### `szTrackerCtxName` [in]

The context name under which tracker information is reported.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_FAIL, and S_OK.

## Remarks

Because no component is associated with this tracker property, tracker activity is reported as arising from a component with the name specified by *szTrackerAppName*.

## See also

[IServiceTrackerConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iservicetrackerconfig)