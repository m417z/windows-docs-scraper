# IRemoteTargetCallbackRemoval::OnRemoteTargetRemoveCanceled

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

A UMDF-based driver's **OnRemoteTargetRemoveCanceled** event callback function performs operations that are necessary when the operating system cancels the removal of a remote I/O target's device.

## Parameters

### `pWdfRemoteTarget` [in]

A pointer to the [IWDFRemoteTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfremotetarget) interface of a remote target object that represents a [remote I/O target](https://learn.microsoft.com/windows-hardware/drivers/wdf/general-i-o-targets-in-umdf). The driver obtains this pointer when it calls [IWDFDevice2::CreateRemoteTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-createremotetarget).

## Remarks

If your driver provides an **OnRemoteTargetRemoveCanceled** event callback function, the callback function must do the following:

1. Call [IWDFRemoteTarget::Reopen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-reopen).
2. Do any driver-specific actions that your driver requires to restart I/O to the remote I/O target.

If the driver does not provide this callback function, the framework calls **IWDFRemoteTarget::Reopen** for the driver.

For more information about the **OnRemoteTargetRemoveCanceled** event callback function, see [Controlling a General I/O Target's State in UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/controlling-a-general-i-o-target-s-state-in-umdf).

## See also

[IRemoteTargetCallbackRemoval](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iremotetargetcallbackremoval)

[IRemoteTargetCallbackRemoval::OnRemoteTargetQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iremotetargetcallbackremoval-onremotetargetqueryremove)

[IRemoteTargetCallbackRemoval::OnRemoteTargetRemoveComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iremotetargetcallbackremoval-onremotetargetremovecomplete)