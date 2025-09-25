## Description

**STOR_THREAD_START_ROUTINE** provides an entry point for a storage miniport-created system thread.

## Parameters

### `StartContext` [in]

A caller-supplied pointer to miniport-defined context information that was specified in the **StartContext** parameter in a previous call to [**StorPortCreateSystemThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportcreatesystemthread). **StartContext** can be NULL.

## Remarks

## See also

[**StorPortCreateSystemThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportcreatesystemthread)