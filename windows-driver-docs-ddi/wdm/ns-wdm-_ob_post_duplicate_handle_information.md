# _OB_POST_DUPLICATE_HANDLE_INFORMATION structure

## Description

The **OB_POST_DUPLICATE_HANDLE_INFORMATION** structure provides information to an [ObjectPostCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_post_operation_callback) routine about a thread or process handle that has been duplicated.

## Members

### `GrantedAccess`

An [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that specifies the access that is granted for the handle.

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[ObjectPostCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pob_post_operation_callback)