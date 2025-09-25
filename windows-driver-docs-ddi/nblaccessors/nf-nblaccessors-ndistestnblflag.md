# NdisTestNblFlag macro

## Description

The **NdisTestNblFlag** macro retrieves the current setting of a flag in a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

### `_F`

The flag in the **NblFlags** member of the **NET_BUFFER_LIST** structure for which to retrieve the current setting.

## Return value

**NdisTestNblFlag** returns **TRUE** if the flag that is specified in the *\_F* parameter is set. Otherwise, this macro returns **FALSE**.

## Remarks

NDIS drivers use the **NdisTestNblFlag** macro to retrieve the setting of the specified flag (*\_F*) in the **NblFlags** member of a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

For more information about the flags, see the **NblFlags** member on the **NET_BUFFER_LIST** topic.

## See also

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)