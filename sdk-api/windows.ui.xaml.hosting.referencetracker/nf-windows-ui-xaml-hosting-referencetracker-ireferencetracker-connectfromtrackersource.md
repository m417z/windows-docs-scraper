# IReferenceTracker::ConnectFromTrackerSource (windows.ui.xaml.hosting.referencetracker.h)

## Description

Indicates that a reference tracker source has created its first COM reference on a reference tracker object.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is called, for example, when a runtime-callable wrapper is created to a XAML object, such as when a XAML object is returned as an **out** parameter argument.

## See also

[IReferenceTracker](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.hosting.referencetracker/nn-windows-ui-xaml-hosting-referencetracker-ireferencetracker)