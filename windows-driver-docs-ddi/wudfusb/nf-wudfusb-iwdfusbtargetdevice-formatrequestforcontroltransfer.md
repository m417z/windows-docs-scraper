# IWDFUsbTargetDevice::FormatRequestForControlTransfer

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **FormatRequestForControlTransfer** method formats an I/O request object for a USB control transfer.

## Parameters

### `pRequest` [in]

A pointer to the [IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest) interface for the request object to format.

### `SetupPacket` [in]

A pointer to a [WINUSB_SETUP_PACKET](https://learn.microsoft.com/windows/win32/api/winusb/ns-winusb-winusb_setup_packet) for the control transfer.

### `pMemory` [in, optional]

A pointer to the [IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory) interface that is used to access the buffer that is used for the control transfer. This parameter is optional.

### `TransferOffset` [in, optional]

A pointer to a [WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ns-wudfddi_types-_wdfmemory_offset) structure that describes the memory offset that is used for the control transfer. This parameter is optional.

## Return value

**FormatRequestForControlTransfer** returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | [FormatRequestForControlTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetdevice-formatrequestforcontroltransfer) successfully formatted an I/O request object. |
| **E_OUTOFMEMORY** | [FormatRequestForControlTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetdevice-formatrequestforcontroltransfer) encountered an allocation failure. |
| **E_INVALIDARG** | The memory offset that the *TransferOffset* parameter specified was invalid. |

## Remarks

After a UMDF driver calls **FormatRequestForControlTransfer** to format an I/O request for a control transfer operation, the framework can subsequently send the request to the I/O target.

#### Examples

The following code example is taken from the [wdf_osrfx2_lab](https://learn.microsoft.com/samples/browse/?redirectedfrom=MSDN-samples) sample in the WDK.

```
    WINUSB_CONTROL_SETUP_PACKET setupPacket;

    ULONG bytesTransferred;

    HRESULT hr = S_OK;

    //
    // Setup the control packet.
    //

    WINUSB_CONTROL_SETUP_PACKET_INIT( &setupPacket,
                                      BmRequestHostToDevice,
                                      BmRequestToDevice,
                                      USBFX2LK_SET_BARGRAPH_DISPLAY,
                                      0,
                                      0 );

    //
    // Issue the request to WinUsb.
    //

    hr = SendControlTransferSynchronously(
                &(setupPacket.WinUsb),
                (PUCHAR) BarGraphState,
                sizeof(BAR_GRAPH_STATE),
                &bytesTransferred
                );
...

HRESULT
CMyDevice::SendControlTransferSynchronously(
    _In_ PWINUSB_SETUP_PACKET SetupPacket,
    _Inout_updates_(BufferLength) PBYTE Buffer,
    _In_ ULONG BufferLength,
    _Out_ PULONG LengthTransferred
    )
{
    HRESULT hr = S_OK;
    IWDFIoRequest *pWdfRequest = NULL;
    IWDFDriver * FxDriver = NULL;
    IWDFMemory * FxMemory = NULL;
    IWDFRequestCompletionParams * FxComplParams = NULL;
    IWDFUsbRequestCompletionParams * FxUsbComplParams = NULL;

    *LengthTransferred = 0;

    hr = m_FxDevice->CreateRequest( NULL, //pCallbackInterface
                                    NULL, //pParentObject
                                    &pWdfRequest);

    if (SUCCEEDED(hr))
    {
        m_FxDevice->GetDriver(&FxDriver);

        hr = FxDriver->CreatePreallocatedWdfMemory( Buffer,
                                                    BufferLength,
                                                    NULL, //pCallbackInterface
                                                    pWdfRequest, //pParetObject
                                                    &FxMemory );
    }

    if (SUCCEEDED(hr))
    {
        hr = m_pIUsbTargetDevice->FormatRequestForControlTransfer( pWdfRequest,
                                                                   SetupPacket,
                                                                   FxMemory,
                                                                   NULL); //TransferOffset
    }

```

## See also

[IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest)

[IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory)

[IWDFUsbTargetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbtargetdevice)

[WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ns-wudfddi_types-_wdfmemory_offset)