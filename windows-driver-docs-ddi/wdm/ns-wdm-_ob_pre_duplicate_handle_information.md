# _OB_PRE_DUPLICATE_HANDLE_INFORMATION structure

## Description

The **OB_PRE_DUPLICATE_HANDLE_INFORMATION** structure provides information to an [*ObjectPreCallback*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_pre_operation_callback) routine about a thread or process handle that is being duplicated.

## Members

### `DesiredAccess`

An [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that specifies the access rights to grant for the handle. By default, this member equals *OriginalDesiredAccess*, but the [*ObjectPreCallback*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_pre_operation_callback) routine can modify this value to restrict the access that is granted. For a description of the access rights that drivers can use, see [OB_PRE_CREATE_HANDLE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ob_pre_create_handle_information).

### `OriginalDesiredAccess`

An ACCESS_MASK value that specifies the original access that was requested for the handle.

### `SourceProcess`

A pointer to the process object for the process that is the source of the handle.

### `TargetProcess`

A pointer to the process object for the process that receives the duplicated handle.

## Remarks

You can never add access rights beyond what is specified in the **DesiredAccess** member. If the access right is listed as a modifiable flag, the access right can be removed.

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[*ObjectPreCallback*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_pre_operation_callback)