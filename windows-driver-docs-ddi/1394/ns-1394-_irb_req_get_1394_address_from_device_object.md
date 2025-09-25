# _IRB_REQ_GET_1394_ADDRESS_FROM_DEVICE_OBJECT structure

## Description

This structure contains the fields necessary to carry out a Get1394AddressFromDeviceObject request.

## Members

### `fulFlags`

Specifies which device's node address we are querying. Zero indicates the calling device. USE_LOCAL_NODE indicates the local host controller.

### `NodeAddress`

Contains the NODE_ADDRESS structure describing the device's node address. In the case of virtual devices, the bus driver returns the node address of the host controller in the stack where the virtual device's device object is loaded.