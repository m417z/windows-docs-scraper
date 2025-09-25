# IWDFRemoteTarget::Stop

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **Stop** method temporarily stops a [remote I/O target](https://learn.microsoft.com/windows-hardware/drivers/wdf/general-i-o-targets-in-umdf).

## Parameters

### `Action` [in]

A [WDF_IO_TARGET_SENT_IO_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ne-wdfiotarget-_wdf_io_target_sent_io_action)-typed value that specifies how the framework should handle I/O requests that the driver has sent to the remote I/O target, if the target has not completed the requests.

## Return value

**Stop** always returns S_OK.

## Remarks

If your driver can detect recoverable errors on a remote I/O target, you might want your driver to call **Stop** to temporarily stop sending requests, and later call [IWDFRemoteTarget::Start](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-start) to resume sending requests.

For more information about **Stop**, and how to use remote I/O targets in UMDF-based drivers, see [Controlling a General I/O Target's State in UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/controlling-a-general-i-o-target-s-state-in-umdf).

#### Examples

The following code example stops a remote I/O target.

```
RemoteTarget->Stop();
```

## See also

[IWDFRemoteTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfremotetarget)

[IWDFRemoteTarget::Start](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-start)