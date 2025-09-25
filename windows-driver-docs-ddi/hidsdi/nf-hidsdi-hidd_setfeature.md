# HidD_SetFeature function

## Description

The **HidD_SetFeature** routine sends a feature report to a [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections).

## Parameters

### `HidDeviceObject` [in]

An open handle to a top-level collection.

### `ReportBuffer` [in]

Pointer to a caller-allocated feature report buffer that the caller uses to specify a HID report ID.

For more information about this parameter, see the [Remarks](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_setfeature#remarks) section.

### `ReportBufferLength` [in]

The size of the report buffer in bytes. The report buffer must be large enough to hold the feature report plus one additional byte that specifies a nonzero report ID. If report ID is not used, the ID value is zero.

## Return value

If **HidD_SetFeature** succeeds, it returns **TRUE**; otherwise, it returns **FALSE**. Use **[GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror)** to get extended error information.

## Remarks

The correct _ReportBufferLength_ is specified by the _FeatureReportByteLength_ member of a top-level collection's [HIDP_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_caps) structure returned from [HidP_GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getcaps) call.

Before it calls the **HidD_SetFeature** routine, the caller must do the following:

- If the [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) includes report IDs, the caller must set the first byte of the _ReportBuffer_ parameter to a nonzero report ID.
- If the [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) does not include report IDs, the caller must set the first byte of the _ReportBuffer_ parameter to zero.
- The feature report is referenced by the _ReportBuffer_ parameter. Depending on the report ID, the caller prepares the report by calling one of the following functions:
    - [HidP_SetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_setdata)
    - [HidP_SetScaledUsageValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_setscaledusagevalue)
    - [HidP_SetUsages](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_setusages)
    - [HidP_SetUsageValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_setusagevalue)
    - [HidP_SetUsageValueArray](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_setusagevaluearray)

For an example of how to prepare and a HID report and send it to a [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections), see the [HClient](https://learn.microsoft.com/samples/microsoft/windows-driver-samples/hclient-sample-application/) sample application.

Only user-mode applications can call **HidD_SetFeature**. Kernel-mode drivers can use an [IOCTL_HID_SET_FEATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_set_feature) request.

## See also

- [Sending HID Reports](https://learn.microsoft.com/windows-hardware/drivers/hid/sending-hid-reports)
- [Interpreting HID Reports](https://learn.microsoft.com/windows-hardware/drivers/hid/interpreting-hid-reports)
- [HidD_GetFeature](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getfeature)
- [HidD_GetInputReport](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getinputreport)
- [HidD_SetOutputReport](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_setoutputreport)
- [HIDP_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_caps)
- [HidP_GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getcaps)
- [IOCTL_HID_GET_FEATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_feature)
- [IOCTL_HID_GET_INPUT_REPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_input_report)
- [IOCTL_HID_SET_FEATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_set_feature)
- [IOCTL_HID_SET_OUTPUT_REPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_set_output_report)