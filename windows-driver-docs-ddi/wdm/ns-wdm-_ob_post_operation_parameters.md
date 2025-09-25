# _OB_POST_OPERATION_PARAMETERS structure

## Description

The **OB_POST_OPERATION_PARAMETERS** union describes the operation-specific parameters for an [ObjectPostCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_post_operation_callback) routine.

## Members

### `CreateHandleInformation`

An [OB_POST_CREATE_HANDLE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ob_post_create_handle_information) structure that contains information that is specific to a handle that is being opened.

### `DuplicateHandleInformation`

An [OB_POST_DUPLICATE_HANDLE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ob_post_duplicate_handle_information) structure that contains information that is specific to a handle that is being duplicated.

## See also

[OB_POST_CREATE_HANDLE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ob_post_create_handle_information)

[OB_POST_DUPLICATE_HANDLE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ob_post_duplicate_handle_information)

[ObjectPostCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_post_operation_callback)