# IReferenceTrackerTarget::Unpeg (windows.ui.xaml.hosting.referencetracker.h)

## Description

Marks that the reference tracker target is no longer in use by the XAML framework, and can be collected.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Note** You do not need to have parity between calls to [Peg](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.hosting.referencetracker/nf-windows-ui-xaml-hosting-referencetracker-ireferencetrackertarget-peg) and **Unpeg**. A single call to **Unpeg** will remove the marker set in all previous calls to **Peg**.

## See also

[IReferenceTrackerTarget](https://learn.microsoft.com/windows/desktop/api/windows.ui.xaml.hosting.referencetracker/nn-windows-ui-xaml-hosting-referencetracker-ireferencetrackertarget)