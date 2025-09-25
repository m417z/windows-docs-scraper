# IReferenceTracker::FindTrackerTargets (windows.ui.xaml.hosting.referencetracker.h)

## Description

Finds out what reference tracker targets are reachable from a reference tracker source; must be called by a garbage collector between calls to [ReferenceTrackingStarted](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.hosting.referencetracker/nf-windows-ui-xaml-hosting-referencetracker-ireferencetrackermanager-referencetrackingstarted) and [FindTrackerTargetsCompleted](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.hosting.referencetracker/nf-windows-ui-xaml-hosting-referencetracker-ireferencetrackermanager-findtrackertargetscompleted).

## Parameters

### `callback` [in]

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IReferenceTracker](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.hosting.referencetracker/nn-windows-ui-xaml-hosting-referencetracker-ireferencetracker)