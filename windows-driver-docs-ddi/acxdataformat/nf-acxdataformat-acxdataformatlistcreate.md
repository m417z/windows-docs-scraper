## Description

The **AcxDataFormatListCreate** function creates a new ACX data format list.

## Parameters

### `Device` [in]

The [WDFDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/) to which the data format list applies.

### `Attributes` [in]

Pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure used to describe the *Device*.

### `Config` [in]

Pointer to an [ACX_DATAFORMAT_LIST_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/ns-acxdataformat-acx_dataformat_list_config) structure used to configure the *DataFormatList*.

### `DataFormatList` [out]

Pointer to the newly created ACX data format list.

## Return value

The method returns **STATUS_SUCCESS** if the operation succeeds. Otherwise, this method might return an appropriate **[NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)** error code.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [WDFDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/)
- [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)
- [ACX_DATAFORMAT_LIST_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/ns-acxdataformat-acx_dataformat_list_config)
- [acxdataformat.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/)