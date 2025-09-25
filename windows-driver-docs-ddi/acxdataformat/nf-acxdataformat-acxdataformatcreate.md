## Description

The **AcxDataFormatCreate** function is used to create a data format for use by an audio class extension (ACX) driver.

## Parameters

### `Device` [in]

A WDFDEVICE object (described in [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects)) that will be associated with the data format.

### `Attributes` [in]

A pointer to the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure to use when creating the data format

### `Config` [in]

A pointer to the [ACX_DATAFORMAT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/ns-acxdataformat-acx_dataformat_config) structure to use when creating the data format.

### `DataFormat` [out]

A pointer to the newly created data format.

## Return value

The method returns **STATUS_SUCCESS** if the operation succeeds. Otherwise, this method might return an appropriate **[NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)** error code.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects)
- [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)
- [ACX_DATAFORMAT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/ns-acxdataformat-acx_dataformat_config)
- [acxdataformat.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxdataformat/)