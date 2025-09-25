# IReferenceTrackerHost::GetTrackerTarget (windows.ui.xaml.hosting.referencetracker.h)

## Description

Requests the host to provide a reference tracker target that references a reference tracker source. This tracker target then controls the lifetime of the tracker source.

## Parameters

### `unknown`

The reference tracker source.

### `newReference`

The reference tracker target.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 For example, after calling this method, calling [Peg](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.hosting.referencetracker/nf-windows-ui-xaml-hosting-referencetracker-ireferencetrackertarget-peg) on the tracker target will prevent the tracker source from being collected.

## See also

[IReferenceTrackerHost](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.hosting.referencetracker/nn-windows-ui-xaml-hosting-referencetracker-ireferencetrackerhost)