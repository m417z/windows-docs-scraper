# IWDFRemoteTarget::CloseForQueryRemove

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **CloseForQueryRemove** method closes a [remote I/O target](https://learn.microsoft.com/windows-hardware/drivers/wdf/general-i-o-targets-in-umdf) because the operating system might allow the device to be removed.

## Return value

The **CloseForQueryRemove** method always returns S_OK.

## Remarks

If your driver provides an [IRemoteTargetCallbackRemoval::OnRemoteTargetQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iremotetargetcallbackremoval-onremotetargetqueryremove) callback function, the callback function must call **CloseForQueryRemove** if it returns **TRUE** to indicate that the device can be removed.

The **CloseForQueryRemove** method completes or cancels all I/O requests that the driver has sent to the I/O target.

After a driver calls **CloseForQueryRemove**, the driver cannot send I/O requests to the I/O target until it calls [IWDFRemoteTarget::Reopen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-reopen).

For more information about the **CloseForQueryRemove** method, see [Controlling a General I/O Target's State in UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/controlling-a-general-i-o-target-s-state-in-umdf).

#### Examples

The following code example shows an [IRemoteTargetCallbackRemoval::OnRemoteTargetQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iremotetargetcallbackremoval-onremotetargetqueryremove) callback function that calls **CloseForQueryRemove**.

```
BOOL
STDMETHODCALLTYPE
CMyRemoteTarget::OnRemoteTargetQueryRemove(
    __in IWDFRemoteTarget  *FxTarget
    )
{
    //
    // Here, do any driver-specific actions that your driver requires
    // to stop sending I/O requests to the I/O target.
    //
...
    //
    // Close the target.
    //
    FxTarget->CloseForQueryRemove();

    //
    // Return TRUE if you want to allow removal of the device.
    //
    return TRUE;
}
```

## See also

[IWDFRemoteTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfremotetarget)

[IWDFRemoteTarget::Close](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-close)