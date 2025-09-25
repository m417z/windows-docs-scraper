# IWDFRemoteTarget::Start

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **IWDFRemoteTarget::Start** method restarts a [remote I/O target](https://learn.microsoft.com/windows-hardware/drivers/wdf/general-i-o-targets-in-umdf) that is stopped.

## Return value

**Start** returns S_OK if the operation succeeds. Otherwise, the method might return the following value:

| Return code | Description |
| --- | --- |
| **HRESULT_FROM_NT (STATUS_INVALID_DEVICE_STATE)** | The remote I/O target object was deleted. |

This method might return one of the other values that Winerror.h contains.

## Remarks

The **Start** method resumes processing any I/O requests that are in queued to the remote I/O target. After a driver calls [IWDFRemoteTarget::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-stop), the driver must call **Start** so the framework can resume sending I/O requests to the I/O target.

For more information about **Start**, and how to use remote I/O targets in UMDF-based drivers, see [Controlling a General I/O Target's State in UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/controlling-a-general-i-o-target-s-state-in-umdf).

#### Examples

The following code example restarts a remote I/O target.

```
if (S_OK == RemoteTarget->Start())
{
    //
    // Resume sending I/O requests to the I/O target.
    //
...}
```

## See also

[IWDFRemoteTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfremotetarget)

[IWDFRemoteTarget::Stop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-stop)