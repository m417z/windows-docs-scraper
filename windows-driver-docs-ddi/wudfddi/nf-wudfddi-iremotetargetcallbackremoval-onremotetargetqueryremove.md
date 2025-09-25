# IRemoteTargetCallbackRemoval::OnRemoteTargetQueryRemove

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

A UMDF-based driver's **OnRemoteTargetQueryRemove** event callback function determines whether a remote I/O target's device can be stopped and removed.

## Parameters

### `pWdfRemoteTarget` [in]

A pointer to the [IWDFRemoteTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfremotetarget) interface of a remote target object that represents a [remote I/O target](https://learn.microsoft.com/windows-hardware/drivers/wdf/general-i-o-targets-in-umdf). The driver obtains this pointer when it calls [IWDFDevice2::CreateRemoteTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-createremotetarget).

## Return value

If the driver determines that the device can be stopped and removed, the **OnRemoteTargetQueryRemove** event callback function must return **TRUE**. Otherwise, the callback function must return **FALSE**.

## Remarks

If your driver provides an **OnRemoteTargetQueryRemove** event callback function, the callback function should determine if the operating system should allow removal of the device. If the driver determines that the device can be removed, it should do the following:

1. Do any driver-specific actions needed to stop I/O to the remote target.
2. Call [IWDFRemoteTarget::CloseForQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-closeforqueryremove).
3. Return **TRUE** to indicate that the removal can occur.

If the driver determines that the device should not be removed, the callback function must return **FALSE**. Typically, drivers should avoid returning **FALSE**, because a **FALSE** return value can cause Windows to restart.

If the driver does not provide this callback function, the framework calls [IWDFRemoteTarget::CloseForQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-closeforqueryremove) for the driver. In other words, the framework always allows the device to be removed unless the driver provides an **OnRemoteTargetQueryRemove** event callback function.

For more information about the **OnRemoteTargetQueryRemove** event callback function, see [Controlling a General I/O Target's State in UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/controlling-a-general-i-o-target-s-state-in-umdf).

## See also

[IRemoteTargetCallbackRemoval](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iremotetargetcallbackremoval)

[IRemoteTargetCallbackRemoval::OnRemoteTargetRemoveCanceled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iremotetargetcallbackremoval-onremotetargetremovecanceled)

[IRemoteTargetCallbackRemoval::OnRemoteTargetRemoveComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iremotetargetcallbackremoval-onremotetargetremovecomplete)