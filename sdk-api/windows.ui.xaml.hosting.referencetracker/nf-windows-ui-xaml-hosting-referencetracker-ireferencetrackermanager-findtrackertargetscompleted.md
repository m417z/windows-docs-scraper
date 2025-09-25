# IReferenceTrackerManager::FindTrackerTargetsCompleted (windows.ui.xaml.hosting.referencetracker.h)

## Description

Indicates that a garbage collection system has finished making all the calls it needs to [IReferenceTracker::FindTrackerTargets](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.hosting.referencetracker/nf-windows-ui-xaml-hosting-referencetracker-ireferencetracker-findtrackertargets); by this time, XAML has pegged all reference tracker targets that it wants to protect.

## Parameters

### `findFailed` [in]

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IReferenceTrackerManager](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.hosting.referencetracker/nn-windows-ui-xaml-hosting-referencetracker-ireferencetrackermanager)