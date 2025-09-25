# DXGKDDI_QUERY_INTERFACE callback function

## Description

The **DxgkDdiQueryInterface** function returns a functional interface that is implemented by the display miniport driver.

## Parameters

### `MiniportDeviceContext` [in]

A handle to a context block associated with a display adapter. The display miniport driver's [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to *Dxgkrnl*.

### `QueryInterface` [in]

A pointer to a [**QUERY_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_query_interface) structure in which the display miniport driver should return information about the interface it supports.

## Return value

**DxgkDdiQueryInterface** returns STATUS_SUCCESS if it succeeds; otherwise, it returns an appropriate NTSTATUS code. If a display miniport driver doesn't support the requested interface, it must return STATUS_NOT_SUPPORTED. By returning STATUS_NOT_SUPPORTED, the display miniport driver informs the operating system to pass the query on to the next driver.

## Remarks

**DxgkDdiQueryInterface** exposes a communication mechanism between the display miniport driver and the driver of a child device (for example, a video capture device). A display miniport driver that exposes such a mechanism should implement this function.

**DxgkDdiQueryInterface** should fill in the members of the [**INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure that **QueryInterface->Interface** points to as follows:

* Set **Size** to the number of bytes in the INTERFACE structure. This value must not exceed the number of bytes specified by **QueryInterface**->**Size**.

* Set **Version** to the version of the interface being returned by the display miniport driver. The display miniport driver should best match the version requested by the child driver in **QueryInterface**->**Version**.

* Set **Context** to point to a display miniport driver-defined context for the interface. Typically, a display miniport driver would set **Context** to the handle to the display adapter's context block that is identified by **MiniportDeviceContext**.

* Initialize **InterfaceReference** and **InterfaceDereference** to point to the display miniport driver-implemented reference and dereference routines for this interface.

* Initialize all additional interface-specific members to point to the appropriate routines of the interface being exposed.

**DxgkDdiQueryInterface** runs at IRQL = PASSIVE_LEVEL and should be made pageable.

## See also

[**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[**DxgkDdiQueryChildRelations**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations)

[**QUERY_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_query_interface)