# IReferenceTrackerTarget::AddRefFromReferenceTracker (windows.ui.xaml.hosting.referencetracker.h)

## Description

Indicates that the reference tracker is returning the target XAML object(s) from previous calls to [FindTrackerTargets](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.hosting.referencetracker/nf-windows-ui-xaml-hosting-referencetracker-ireferencetracker-findtrackertargets). Note that the reference is held by the reference tracker object in lieu of **IUnknown::AddRef**.

## Remarks

 When the XAML framework keeps this reference in lieu of a COM reference, it indicates that the framework must call your implementation of [Peg](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.hosting.referencetracker/nf-windows-ui-xaml-hosting-referencetracker-ireferencetrackertarget-peg) to ensure that the target does not get collected.

## See also

[IReferenceTrackerTarget](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.hosting.referencetracker/nn-windows-ui-xaml-hosting-referencetracker-ireferencetrackertarget)