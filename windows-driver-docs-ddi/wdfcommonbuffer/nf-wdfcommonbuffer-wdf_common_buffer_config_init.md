# WDF_COMMON_BUFFER_CONFIG_INIT function

## Description

[Applies to KMDF only]

The **WDF_COMMON_BUFFER_CONFIG_INIT** function initializes a [WDF_COMMON_BUFFER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/ns-wdfcommonbuffer-_wdf_common_buffer_config) structure.

## Parameters

### `Config` [out]

A pointer to a [WDF_COMMON_BUFFER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/ns-wdfcommonbuffer-_wdf_common_buffer_config) structure.

### `AlignmentRequirement` [in]

A value for the **AlignmentRequirement** member of the [WDF_COMMON_BUFFER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/ns-wdfcommonbuffer-_wdf_common_buffer_config) structure. This value specifies the alignment requirement for the common buffer that the structure describes.

## Remarks

The **WDF_COMMON_BUFFER_CONFIG_INIT** function zeros the specified [WDF_COMMON_BUFFER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/ns-wdfcommonbuffer-_wdf_common_buffer_config) structure and sets the structure's **AlignmentRequirement** member to the specified value.

## See also

[WDF_COMMON_BUFFER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/ns-wdfcommonbuffer-_wdf_common_buffer_config)