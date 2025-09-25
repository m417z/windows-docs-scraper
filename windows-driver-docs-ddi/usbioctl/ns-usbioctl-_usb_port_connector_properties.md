# _USB_PORT_CONNECTOR_PROPERTIES structure

## Description

The **USB_PORT_CONNECTOR_PROPERTIES** structure is used with the [IOCTL_USB_GET_PORT_CONNECTOR_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_port_connector_properties) I/O control request to retrieve information about a port on a particular SuperSpeed hub.

## Members

### `ConnectionIndex`

The port number being queried in the request. **ConnectionIndex** is specified by the caller. If there are *n* ports on the SuperSpeed hub, the ports are numbered from 1 to *n*. To get the number of ports, the caller first sends an [IOCTL_USB_GET_HUB_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_hub_information_ex) I/O control request. The request retrieves the highest port number on the hub.

### `ActualLength`

The number of bytes required to hold the entire **USB_PORT_CONNECTOR_PROPERTIES**
structure including the string that contains the symbolic link name of the companion hub. That string is stored in the **CompanionHubSymbolicLinkName** member. The **ActualLength** value is returned by the [IOCTL_USB_GET_PORT_CONNECTOR_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_port_connector_properties) request and used by the caller to allocate a buffer to hold the received information. For details, see **IOCTL_USB_GET_PORT_CONNECTOR_PROPERTIES**.

### `UsbPortProperties`

The port properties. Upon completion of the [IOCTL_USB_GET_PORT_CONNECTOR_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_port_connector_properties) request, **UsbPortProperties** contains a bitwise **OR** of one or more flags indicating the properties and capabilities of the port. The flags are defined in [USB_PORT_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_port_properties).

### `CompanionIndex`

The index of the companion port that is associated with the port being queried (specified by **ConnectionIndex**). If there are *n* companion ports, those ports are indexed from 0 to *n*–1.

If a port is mapped to more than one companion port, **CompanionIndex** is incremented on multiple queries to enumerate all companion ports.

For SuperSpeed hubs and xHCI controllers, **CompanionIndex** is always 0. For more information, see Remarks.

### `CompanionPortNumber`

The port number of the companion port that is given by **CompanionIndex**. If the port being queried shares a USB connector with a port on another hub, **CompanionPortNumber** indicates the port number of the port on the other hub.

**Note** For root hub of an xHCI controller, the shared port might be on the same hub.

### `CompanionHubSymbolicLinkName`

The Unicode string that contains the symbolic link of the companion hub that shares the USB connector. If a companion hub exists, **CompanionPortNumber** is nonzero. Otherwise, **CompanionHubSymbolicLinkName [0]** is **NULL**.

## Remarks

A SuperSpeed 3.0 hub contains two independent hub implementations. One is for USB 2.0 devices, and the hub implementation is similar to existing 2.0 hubs. The other hub is only for SuperSpeed devices. Because the USB 2.0 and 3.0 bus signaling are electrically independent, both of those hubs operate simultaneously. Therefore, when a SuperSpeed hub is connected to the host, Windows enumerates the two hubs independently; one hub is associated with a USB 2.0 port, and the other hub with a USB 3.0 port. Each hub has its downstream and upstream ports. USB physical connectors are shared between ports that are associated with those two hub implementations.

 Similarly, an xHCI controller must be able to handle SuperSpeed, high-speed, full-speed, and low-speed devices. The USB 3.0 specification requires an xHCI controller to contain two independent execution units each for USB 3.0 and USB 2.0 bus speeds. The USB 3.0 execution unit handles SuperSpeed traffic on the bus. The USB 2.0 execution unit must handle low, full, and high speed traffic. That requirement can be met in many ways. For instance, in one implementation, the USB 2.0 execution unit can have either a downstream USB 1.1 execution unit or a downstream USB 2.0 hub. The other execution unit handles SuperSpeed traffic on the bus. For instance, in one implementation, the xHCI controller can have a downstream USB 2.0 hub (instead of a USB 2.0 host controller) with a transaction translator to handle full-speed and low-speed traffic. That downstream hub shares connectors with the ports of the SuperSpeed root hub.

 In cases where USB connectors are shared, the port that is being queried through the [IOCTL_USB_GET_PORT_CONNECTOR_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_port_connector_properties) I/O control request is specified by **ConnectionIndex**, and the port that shares the connector is called the *companion port*. Upon completion of the request, the **CompanionIndex**, **CompanionPortNumber**, and **CompanionHubSymbolicLinkName** members of **USB_PORT_CONNECTOR_PROPERTIES** can be used to determine the port routing in those cases.

If more than one companion port is associated with the port that is being queried, the application can get information about all companion ports by sending the [IOCTL_USB_GET_PORT_CONNECTOR_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_port_connector_properties) I/O control request in a loop and incrementing the **CompanionIndex** value in each iteration. When all of the ports have been enumerated and there is no port associated with the index specified in **CompanionIndex**, the request completes successfully, **CompanionPortNumber** is set to 0, and **CompanionHubSymbolicLinkName** is NULL.

To get information about the operating speed of a device attached to a particular port, the application can send the [IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_information_ex_v2) I/O control request.

## See also

[IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_information_ex_v2)

[IOCTL_USB_GET_PORT_CONNECTOR_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_port_connector_properties)

[USB_HUB_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hub_information_ex)

[USB_PORT_CONNECTOR_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_port_connector_properties)

[USB_PORT_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_port_properties)