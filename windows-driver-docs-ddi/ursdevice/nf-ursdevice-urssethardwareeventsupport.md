# UrsSetHardwareEventSupport function

## Description

Indicates the client driver's support for reporting new hardware events.

## Parameters

### `Device` [in]

A handle to the framework device object that the client driver retrieved in the previous call to [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `HardwareEventReportingSupported` [in]

A boolean value that indicates support for reporting hardware events.

TRUE indicates the client driver will report hardware events by calling [UrsReportHardwareEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/nf-ursdevice-ursreporthardwareevent).

FALSE indicates hardware event reporting is not handled by the client driver.

## Remarks

Before the client driver can report hardware events, the client driver for the dual-role controller must indicate to the class extension that the driver supports hardware events by calling this method. Typically, the driver calls **UrsSetHardwareEventSupport** in the driver's [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback function. The driver must not call this method after *EvtDevicePrepareHardware* has returned. Otherwise, the method fails and a break is issued if [Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/what-s-new-in-driver-development) is enabled.

For certain controllers, the client driver might not support role detection before performing a role switch operation. In that case, the client driver must set *HardwareEventReportingSupported* to FALSE. The operating system manages the role of the controller.

Otherwise, if the driver supports role detection, it must set *HardwareEventReportingSupported* to TRUE. This indicates to the class extension that the client driver will handle hardware events, such as ID pin interrupts, and report to the class extension that the role needs to be changed. The driver can report events by calling [UrsReportHardwareEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/nf-ursdevice-ursreporthardwareevent).

#### Examples

```

EVT_WDF_DEVICE_PREPARE_HARDWARE EvtDevicePrepareHardware;

NTSTATUS
EvtDevicePrepareHardware (
    _In_ WDFDEVICE Device,
    _In_ WDFCMRESLIST ResourcesRaw,
    _In_ WDFCMRESLIST ResourcesTranslated
    )
{
    ULONG resourceCount;
    BOOLEAN hasHardwareEventSupport;

    UNREFERENCED_PARAMETER(ResourcesRaw);

    TRY {

        resourceCount = WdfCmResourceListGetCount(ResourcesTranslated);

        ...

        // DetermineHardwareEventSupport determines support by inspecting resources.
        // Implementation not shown.
        hasHardwareEventSupport = DetermineHardwareEventSupport(ResourcesRaw);

        UrsSetHardwareEventSupport(Device, hasHardwareEventSupport);

        if (hasHardwareEventSupport) {
            UrsReportHardwareEvent(Device, UrsHardwareEventIdGround);
        }

        ...

    } FINALLY {
    }

    return STATUS_SUCCESS;
}
```

## See also

[UrsReportHardwareEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/nf-ursdevice-ursreporthardwareevent)