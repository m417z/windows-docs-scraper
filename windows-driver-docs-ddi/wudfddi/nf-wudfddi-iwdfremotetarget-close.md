# IWDFRemoteTarget::Close

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **Close** method closes a [remote I/O target](https://learn.microsoft.com/windows-hardware/drivers/wdf/general-i-o-targets-in-umdf).

## Return value

The **Close** method always returns S_OK.

## Remarks

If your driver provides an [IRemoteTargetCallbackRemoval::OnRemoteTargetRemoveComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iremotetargetcallbackremoval-onremotetargetremovecomplete) callback function, the callback function must call **Close**.

The **Close** method completes or cancels all I/O requests that the driver has sent to the I/O target.

After a driver calls **Close**, the driver cannot send I/O requests to the I/O target.

For more information about the **Close** method, see [Controlling a General I/O Target's State in UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/controlling-a-general-i-o-target-s-state-in-umdf).

#### Examples

The following code example shows an [IRemoteTargetCallbackRemoval::OnRemoteTargetRemoveComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iremotetargetcallbackremoval-onremotetargetremovecomplete) callback function that calls **Close**.

```
VOID
STDMETHODCALLTYPE
CMyRemoteTarget::OnRemoteTargetRemoveComplete(
    __in IWDFRemoteTarget *FxTarget
    )
{
    //
    // Here, do any driver-specific actions that your driver requires
    // to close the remote I/O target.
    //
...
    //
    // Close the target.
    //
    FxTarget->Close();
}
```

## See also

[IWDFRemoteTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfremotetarget)

[IWDFRemoteTarget::CloseForQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-closeforqueryremove)