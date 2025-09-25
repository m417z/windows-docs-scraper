# IReferenceTrackerHost::ReleaseDisconnectedReferenceSources (windows.ui.xaml.hosting.referencetracker.h)

## Description

Requests that the host call **IUnknown::Release** on any reference tracker objects that have been disconnected by a reference source.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

It is not necessary for the **Release** calls to come in on the same thread.
In this call, the CLR calls **WaitForPendingFinalizers**.

## See also

[IReferenceTrackerHost](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.hosting.referencetracker/nn-windows-ui-xaml-hosting-referencetracker-ireferencetrackerhost)