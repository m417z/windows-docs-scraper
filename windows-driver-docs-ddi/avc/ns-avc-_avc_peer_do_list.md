# _AVC_PEER_DO_LIST structure

## Description

The AVC_PEER_DO_LIST describes all nonvirtual (peer) instances of *avc.sys*.

## Members

### `Count`

Ignored on input. On output, set to the number of objects in the list. If zero, the caller must not attempt to dereference the **Objects** member (it is set to **NULL**).

### `Objects`

Ignored on input. On output (and if the **Count** member is not zero) **Objects** contains a pointer to a contiguous array of DEVICE_OBJECT pointers. The caller must release the reference held on each object (by using **ObDereferenceObject**), and free the memory containing the list (by using **ExFreePool**) when finished with it.

## Remarks

This structure is used with the [AVC_FUNCTION_PEER_DO_LIST](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-peer-do-list) function code.

This structure is used only as a member inside the AVC_MULTIFUNC_IRB structure. It is not used by itself.

See [How to Use Avc.sys](https://learn.microsoft.com/windows-hardware/drivers/stream/using-avc-sys) For information about building and sending an AV/C command.

## See also

[AVC_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ne-avc-_tagavc_function)

[AVC_FUNCTION_PEER_DO_LIST](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-peer-do-list)

[AVC_MULTIFUNC_IRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ns-avc-_avc_multifunc_irb)