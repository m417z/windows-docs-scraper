# IReferenceTrackerHost::DisconnectUnusedReferenceSources (windows.ui.xaml.hosting.referencetracker.h)

## Description

Requests that the host perform a garbage collection and remove all unnecessary reference sources.

## Parameters

### `options` [in]

May be 0 or 1; 1 indicates that an application suspend is in progress.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is expected to potentially cause the reference source to call [IReferenceTracker::DisconnectFromTrackerSource](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.hosting.referencetracker/nf-windows-ui-xaml-hosting-referencetracker-ireferencetracker-disconnectfromtrackersource), but it is not necessary to call **IUnknown::Release** immediately on the tracker source. In the CLR, this call triggers a garbage collection, but not a **WaitForPendingFinalizers**. When flags is one, the garbage collection is executed in the **GCCollectionMode.Optimized** state.

## See also

[IReferenceTrackerHost](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.hosting.referencetracker/nn-windows-ui-xaml-hosting-referencetracker-ireferencetrackerhost)