# IWDFDevice::SetPnpState

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **SetPnpState** method turns on or off (or sets to the default state) the specified Plug and Play (PnP) property of a device.

## Parameters

### `State` [in]

A [WDF_PNP_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_pnp_state)-typed value that identifies the PnP property to set.

### `Value` [in]

A WDF_TRI_STATE-typed value that identifies how to set the PnP property that *State* specifies. The following table shows the possible values for *Value*.

| Value | Meaning |
| --- | --- |
| **WdfUseDefault** (0) | Set the PnP property to the default state. |
| **WdfFalse** (1) | Turn off the PnP property. |
| **WdfTrue** (2) | Turn on the PnP property. |

## Remarks

Before the state of the PnP property that **SetPnpState** set can take effect, the driver must call the [IWDFDevice::CommitPnpState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-commitpnpstate) method.

#### Examples

The following code example shows how to indicate that a device failed as the result of a request.

```
VOID
CUmdfHidDevice::OnCompletion(
    __in IWDFIoRequest* WdfRequest,
    __in IWDFIoTarget* /* WdfTarget */,
    __in IWDFRequestCompletionParams* WdfCompletionParams,
    __in PVOID /* Context */
    )
{
    ULONG_PTR bytesRead;

 if (!SUCCEEDED(WdfCompletionParams->GetCompletionStatus()))
    {
        m_WdfDevice->SetPnpState(WdfPnpStateFailed, WdfTrue);
        m_WdfDevice->CommitPnpState();
        return;
    }

    // Lock the device to prevent files from closing.
    m_WdfDevice->AcquireLock();

    // Retrieve the number of bytes that were read.
    bytesRead = WdfCompletionParams->GetInformation();

    // Process the reports.
    ProcessInputReports((PBYTE) m_ReadMemory->GetDataBuffer(NULL), bytesRead);

    m_WdfDevice->ReleaseLock();

    // Release the request.
    m_InterruptReadRequest = NULL;
    WdfRequest->DeleteWdfObject();

    // Send a new request.
    SendInterruptPipeRead();
}
```

## See also

[IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice)

[IWDFDevice::CommitPnpState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-commitpnpstate)

[IWDFDevice::GetPnpState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-getpnpstate)

[WDF_PNP_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_pnp_state)