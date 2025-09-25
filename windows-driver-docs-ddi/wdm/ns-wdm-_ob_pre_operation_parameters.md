# _OB_PRE_OPERATION_PARAMETERS structure

## Description

The **OB_PRE_OPERATION_PARAMETERS** union describes the operation-specific parameters for an [ObjectPreCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_pre_operation_callback) routine.

## Members

### `CreateHandleInformation`

An [OB_PRE_CREATE_HANDLE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ob_pre_create_handle_information) structure that contains information that is specific to a handle that is being opened.

### `DuplicateHandleInformation`

An [OB_PRE_DUPLICATE_HANDLE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ob_pre_duplicate_handle_information)  structure that contains information that is specific to a handle that is being duplicated.

## See also

[OB_PRE_CREATE_HANDLE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ob_pre_create_handle_information)

[OB_PRE_DUPLICATE_HANDLE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ob_pre_duplicate_handle_information)

[ObjectPreCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_pre_operation_callback)