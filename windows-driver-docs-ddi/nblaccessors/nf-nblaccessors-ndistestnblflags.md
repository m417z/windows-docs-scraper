# NdisTestNblFlags macro

## Description

The **NdisTestNblFlags** macro tests the setting of a set of flags in a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

### `_F`

The flags, combined with a bitwise OR operation, in the **NblFlags** member of the **NET_BUFFER_LIST** structure to test.

## Return value

**NdisTestNblFlags** returns **TRUE** if all flags that are specified in the *\_F* parameter are set. Otherwise, this macro returns **FALSE**.

## Remarks

NDIS drivers use the **NdisTestNblFlags** macro to retrieve the state of the specified flags (*\_F*) in the **NblFlags** member of a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

Use **NdisTestNblFlags** to determine whether a set of specified flags are all set.

For more information about the flags, see the **NblFlags** member on the **NET_BUFFER_LIST** topic.

## See also

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)