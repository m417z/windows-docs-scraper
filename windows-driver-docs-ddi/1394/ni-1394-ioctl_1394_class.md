# IOCTL_1394_CLASS IOCTL

## Description

An IEEE 1394 driver uses the [IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control) IRP, with IoControlCode **IOCTL_1394_CLASS**, to communicate with the bus driver. The driver has access to all operations provided by the IEEE 1394 bus and its host controller through this request.

## Parameters

### Major code

### Input buffer

**Parameters->Others.Arguments1** points to an **IRB** structure. The **FunctionNumber** member of the IRB specifies the type of request. The **u** member of the IRB is a union that specifies the request-type-specific parameters of the request. The parameters and their meaning are documented with each request.

Legal requests are as follows:

REQUEST_ALLOCATE_ADDRESS_RANGE

REQUEST_ASYNC_LOCK

REQUEST_ASYNC_READ

REQUEST_ASYNC_STREAM

REQUEST_ASYNC_WRITE

REQUEST_BUS_RESET

REQUEST_BUS_RESET_NOTIFICATION

REQUEST_CONTROL

REQUEST_FREE_ADDRESS_RANGE

REQUEST_GET_ADDR_FROM_DEVICE_OBJECT

REQUEST_GET_CONFIGURATION_INFO

REQUEST_GET_GENERATION_COUNT

REQUEST_GET_LOCAL_HOST_INFO

REQUEST_GET_SPEED_BETWEEN_DEVICES

REQUEST_GET_SPEED_TOPOLOGY_MAPS

REQUEST_ISOCH_ALLOCATE_BANDWIDTH

REQUEST_ISOCH_ALLOCATE_CHANNEL

REQUEST_ISOCH_ALLOCATE_RESOURCES

REQUEST_ISOCH_ATTACH_BUFFERS

REQUEST_ISOCH_DETACH_BUFFERS

REQUEST_ISOCH_FREE_BANDWIDTH

REQUEST_ISOCH_FREE_CHANNEL

REQUEST_ISOCH_FREE_RESOURCES

REQUEST_ISOCH_LISTEN

REQUEST_ISOCH_QUERY_CYCLE_TIME

REQUEST_ISOCH_QUERY_RESOURCES

REQUEST_ISOCH_SET_CHANNEL_BANDWIDTH

REQUEST_ISOCH_STOP

REQUEST_ISOCH_TALK

REQUEST_SEND_PHY_CONFIG_PACKET

REQUEST_SET_DEVICE_XMIT_PROPERTIES

REQUEST_SET_LOCAL_HOST_PROPERTIES

### Input buffer length

### Output buffer

**Parameters->Others.Arguments1** points to the **IRB** structure passed as input. As part of completing the request, the bus driver fills in certain members of the **u** member with information for the driver. The returned information is documented below with each request.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

The information the bus driver returns in the I/O Status Block is documented below with each request.

## See also

IOCTL_IEEE1394_API_REQUEST