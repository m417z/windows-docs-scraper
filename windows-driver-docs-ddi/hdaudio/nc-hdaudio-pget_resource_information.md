# PGET_RESOURCE_INFORMATION callback function

## Description

The `GetResourceInformation` routine retrieves information about hardware resources.

The function pointer type for a `GetResourceInformation` routine is defined as follows.

## Parameters

### `_context` [in]

Specifies the context value from the **Context** member of the [HDAUDIO_BUS_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface), [HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2), or [HDAUDIO_BUS_INTERFACE_BDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_bdl) structure.

### `CodecAddress` [out]

Retrieves a codec address. This parameter points to a caller-allocated UCHAR variable into which the routine writes a codec address. The codec address identifies the serial data in (SDI) line on which the codec supplies response data to the HD Audio bus controller. A bus controller with *n* SDI pins can support up to *n* codecs with addresses that range from 0 to *n*-1.

### `FunctionGroupStartNode` [out]

Retrieves the function group's starting node ID. This parameter points to a caller-allocated UCHAR variable into which the routine writes the node ID. For more information, see the following Remarks section.

## Remarks

A codec contains one or more function groups. Each function group contains some number of nodes that are numbered sequentially beginning with the starting node. For example, if a function group contains three nodes and the starting node has a node ID of 9, the other two nodes in the function group have node IDs 10 and 11. For more information, see the Intel High Definition Audio Specification at the [Intel HD Audio](https://go.microsoft.com/fwlink/p/?linkid=42508) website.

## See also

[HDAUDIO_BUS_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface)

[HDAUDIO_BUS_INTERFACE_BDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_bdl)

[HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2)