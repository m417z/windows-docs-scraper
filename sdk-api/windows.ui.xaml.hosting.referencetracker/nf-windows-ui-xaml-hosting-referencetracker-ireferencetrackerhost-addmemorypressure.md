# IReferenceTrackerHost::AddMemoryPressure (windows.ui.xaml.hosting.referencetracker.h)

## Description

Informs the host of increased memory allocations since the last notification.
The CLR uses this to inform the algorithm that determines when to run a garbage collection.

## Parameters

### `bytesAllocated`

The number of bytes currently allocated.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IReferenceTrackerHost](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.hosting.referencetracker/nn-windows-ui-xaml-hosting-referencetracker-ireferencetrackerhost)