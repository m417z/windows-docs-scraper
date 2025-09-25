## Description

Specifies the type of a [DEV_OBJECT](https://learn.microsoft.com/windows/win32/api/devquerydef/ns-devquerydef-dev_object).

## Constants

### `DevObjectTypeUnknown`

Not a valid object type.

### `DevObjectTypeDeviceInterface`

The object represents a device interface. These are exposed by device drivers to enable an app to talk to the device, typically using device IOCTLs (input output controls). For more information on device interfaces, see [Using a device interface](https://learn.microsoft.com/windows-hardware/drivers/install/using-a-device-interface). For more information on IOCTLs, see [Introduction to I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-i-o-control-codes)

### `DevObjectTypeDeviceContainer`

The object represents a device container, which describe a collection of device objects that exist in the same physical device. For more information, see [Container ID](https://learn.microsoft.com/windows-hardware/drivers/install/container-ids).

### `DevObjectTypeDevice`

The object represents a device. This could also be referred to as a devnode. These devices are objects that represent a piece of the device functionality and optionally have drivers loaded on them. For more information, see [Device instance ID](https://learn.microsoft.com/windows-hardware/drivers/install/device-instance-ids).

### `DevObjectTypeDeviceInterfaceClass`

The object represents a device interface class. Every *DevObjectTypeDeviceInterface* object belongs to a certain device interface class. This is similar to a contract definition. For more information, see [Overview of device interface classes](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-interface-classes).

### `DevObjectTypeAEP`

The object represents a device association endpoint (AEP). AEPs usually represent a device discovered over a wireless or network protocol.

### `DevObjectTypeAEPContainer`

The object represents an AEP container. This object represents a single physical device that might have more than one AEP objects associated with it. For example, if a television supports two different network protocols, the container would be the television. It would also have two AEP objects, one to represent each protocol.

### `DevObjectTypeDeviceInstallerClass`

The object represents a device setup class. For more information, see [Overview of device setup classes](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes).

### `DevObjectTypeDeviceInterfaceDisplay`

The object represents a device interface in the same way as a *DevObjectTypeDeviceInterface* object, but this object has some additional properties added to it that are taken from the device container the device interface is part of.

### `DevObjectTypeDeviceContainerDisplay`

The object is similar to a *DevObjectTypeDeviceContainer* object, but with some extra properties associated with the object.

### `DevObjectTypeAEPService`

The object represents an AEP Service. The object represents a functional service contract exposed by the device. Not all protocols support AEP services. An AEP service can have a single parent AEP and AEP container object.

### `DevObjectTypeDevicePanel`

The object represents a single physical face of a device enclosure.

### `DevObjectTypeAEPProtocol`

The object represents a protocol through which association endpoints (AEPs) can be discovered. You can scope an association endpoint discovery to specific protocols by using the protocol ID. For example, a filter can scope discovery to Bluetooth LE or Bluetooth Classic.

## Remarks

## See also