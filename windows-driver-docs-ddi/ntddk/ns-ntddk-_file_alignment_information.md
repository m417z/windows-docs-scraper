# _FILE_ALIGNMENT_INFORMATION structure

## Description

The **FILE_ALIGNMENT_INFORMATION** structure is used as an argument to the [ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile) routine.

## Members

### `AlignmentRequirement`

The buffer alignment required by the underlying device. For a list of system-defined values, see [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object). The value must be one of the FILE_*XXX*_ALIGNMENT values defined in Wdm.h. For more information, see [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) and [Initializing a Device Object](https://learn.microsoft.com/windows-hardware/drivers/kernel/initializing-a-device-object).

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)

[ZwSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile)