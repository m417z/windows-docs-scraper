# IWDFRemoteTarget::Reopen

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **Reopen** method reopens a [remote I/O target](https://learn.microsoft.com/windows-hardware/drivers/wdf/general-i-o-targets-in-umdf) after it has been temporarily closed.

## Return value

**Reopen** returns S_OK if the operation succeeds. Otherwise, the method might return the following value:

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | The framework's attempt to allocate memory failed. |

This method might return one of the other values that Winerror.h contains.

The framework's [verifier](https://learn.microsoft.com/windows-hardware/drivers/debugger/-verifier) reports an error if the framework cannot open the file.

## Remarks

Typically, a driver calls **Reopen** from within the [IRemoteTargetCallbackRemoval::OnRemoteTargetRemoveCanceled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iremotetargetcallbackremoval-onremotetargetremovecanceled) callback function, but **Reopen** can instead be called after **OnRemoteTargetRemoveCanceled** returns.

Reopen uses the file or interface name that the driver previously specified to [IWDFRemoteTarget::OpenFileByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-openfilebyname) or [IWDFRemoteTarget::OpenRemoteInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-openremoteinterface). If you want to change the file or interface that the driver is using, the driver can call [IWDFRemoteTarget::Close](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-close), and then it can call **OpenFileByName** or **OpenRemoteInterface** instead of **Reopen**.

For more information about **Reopen** and how to use remote I/O targets in UMDF-based drivers, see [Controlling a General I/O Target's State in UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/controlling-a-general-i-o-target-s-state-in-umdf).

#### Examples

The following code example shows an [IRemoteTargetCallbackRemoval::OnRemoteTargetRemoveCanceled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iremotetargetcallbackremoval-onremotetargetremovecanceled) callback function that calls **Reopen**.

```
VOID
STDMETHODCALLTYPE
CMyRemoteTarget::OnRemoteTargetRemoveCanceled(
    __in IWDFRemoteTarget* FxTarget
    )
{
 if (S_OK == (FxTarget->Reopen()))
    {
    //
    // Resume sending I/O requests to the remote target.
    //
    ...
    }
 else
    {
       FxTarget->Close();
    }
}
```

## See also

[IWDFRemoteTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfremotetarget)

[IWDFRemoteTarget::Close](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-close)