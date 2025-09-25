# IReferenceTrackerHost::RemoveMemoryPressure (windows.ui.xaml.hosting.referencetracker.h)

## Description

Informs the host of reduced memory allocations since the last notification.

## Parameters

### `bytesAllocated`

The number of bytes currently allocated.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IReferenceTrackerHost](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.hosting.referencetracker/nn-windows-ui-xaml-hosting-referencetracker-ireferencetrackerhost)