# HidD_GetFeature function

## Description

The **HidD_GetFeature** routine returns a feature report from a specified [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections).

## Parameters

### `HidDeviceObject` [in]

An open handle to a top-level collection.

### `ReportBuffer` [out]

Pointer to a caller-allocated HID report buffer that the caller uses to specify a report ID. **HidD_GetFeature** uses *ReportBuffer* to return the specified feature report.

For more information about this parameter, see the [Remarks](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getfeature#remarks) section.

### `ReportBufferLength` [in]

The size of the report buffer in bytes. The report buffer must be large enough to hold the feature report plus one additional byte that specifies a nonzero report ID. If report ID is not used, the ID value is zero.

## Return value

If **HidD_GetFeature** succeeds, it returns **TRUE**; otherwise, it returns **FALSE**. Use **[GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror)** to get extended error information.

## Remarks

The correct _ReportBufferLength_ is specified by the _FeatureReportByteLength_ member of a top-level collection's [HIDP_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_caps) structure returned from [HidP_GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getcaps) call.

Before it calls the **HidD_GetFeature** routine, the caller must do the following:

- If the [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) includes report IDs, the caller must set the first byte of the *ReportBuffer* parameter to a nonzero report ID.
- If the [top-level collection](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) does not include report IDs, the caller must set the first byte of the *ReportBuffer* parameter to zero.

The feature report is returned in the *ReportBuffer* parameter. Depending on the report ID, the caller parses the report by calling one of the following functions:

- [HidP_GetButtonCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getbuttoncaps)
- [HidP_GetData](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getdata)
- [HidP_GetExtendedAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getextendedattributes)
- [HidP_GetScaledUsageValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getscaledusagevalue)
- [HidP_GetSpecificButtonCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getspecificbuttoncaps)
- [HidP_GetSpecificValueCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getspecificvaluecaps)
- [HidP_GetUsages](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusages)
- [HidP_GetUsagesEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusagesex)
- [HidP_GetUsageValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusagevalue)
- [HidP_GetUsageValueArray](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getusagevaluearray)
- [HidP_GetValueCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getvaluecaps)

For an example of how to parse a HID report, see the [HClient](https://learn.microsoft.com/samples/browse/?redirectedfrom=MSDN-samples) sample application. This sample is located in the MSDN Code Gallery.

Only user-mode applications can call **HidD_GetFeature**. Kernel-mode drivers can use an [IOCTL_HID_GET_FEATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_feature) request.

## See also

- [Obtaining HID Reports](https://learn.microsoft.com/windows-hardware/drivers/hid/obtaining-hid-reports)
- [Interpreting HID Reports](https://learn.microsoft.com/windows-hardware/drivers/hid/interpreting-hid-reports)
- [HidD_GetInputReport](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getinputreport)
- [HidD_SetFeature](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_setfeature)
- [HidD_SetOutputReport](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_setoutputreport)
- [HIDP_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_caps)
- [HidP_GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getcaps)
- [IOCTL_HID_GET_FEATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_feature)
- [IOCTL_HID_GET_INPUT_REPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_get_input_report)
- [IOCTL_HID_SET_FEATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_set_feature)
- [IOCTL_HID_SET_OUTPUT_REPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/ni-hidclass-ioctl_hid_set_output_report)