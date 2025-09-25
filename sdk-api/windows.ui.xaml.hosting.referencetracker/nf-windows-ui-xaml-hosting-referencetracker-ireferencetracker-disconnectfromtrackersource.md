# IReferenceTracker::DisconnectFromTrackerSource (windows.ui.xaml.hosting.referencetracker.h)

## Description

Indicates that a reference tracker source has stopped tracking a reference tracker.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Calling this method does not indicate that the tracker source has released all COM references on the reference tracker.
This method is called by the CLR during garbage collection when a runtime-callable wrapper is collected, but the XAML object does not get released until it is processed by the finalizer thread.

## See also

[IReferenceTracker](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.hosting.referencetracker/nn-windows-ui-xaml-hosting-referencetracker-ireferencetracker)