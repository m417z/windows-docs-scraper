# IReferenceTrackerHost::NotifyEndOfReferenceTrackingOnThread (windows.ui.xaml.hosting.referencetracker.h)

## Description

Notifies the host that reference tracking is no longer available on the calling thread; XAML calls this when the **FrameworkView** is uninitialized.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IReferenceTrackerHost](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.hosting.referencetracker/nn-windows-ui-xaml-hosting-referencetracker-ireferencetrackerhost)