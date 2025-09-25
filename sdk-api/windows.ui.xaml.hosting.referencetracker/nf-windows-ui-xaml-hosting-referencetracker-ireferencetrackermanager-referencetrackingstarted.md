# IReferenceTrackerManager::ReferenceTrackingStarted (windows.ui.xaml.hosting.referencetracker.h)

## Description

Indicates that a garbage collector is performing a collection; when the collection is finished, the garbage collector calls [FindTrackerTargetsCompleted](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.hosting.referencetracker/nf-windows-ui-xaml-hosting-referencetracker-ireferencetrackermanager-findtrackertargetscompleted).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 When this method is called, XAML blocks all threads where it is attempting to update tracked references. Between calls to **ReferenceTrackingStarted** and [ReferenceTrackingCompleted](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.hosting.referencetracker/nf-windows-ui-xaml-hosting-referencetracker-ireferencetrackermanager-referencetrackingcompleted), XAML does not make any calls to reference tracker target objects other than [Peg](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.hosting.referencetracker/nf-windows-ui-xaml-hosting-referencetracker-ireferencetrackertarget-peg) and [Unpeg](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.hosting.referencetracker/nf-windows-ui-xaml-hosting-referencetracker-ireferencetrackertarget-unpeg).

## See also

[IReferenceTrackerManager](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.hosting.referencetracker/nn-windows-ui-xaml-hosting-referencetracker-ireferencetrackermanager)