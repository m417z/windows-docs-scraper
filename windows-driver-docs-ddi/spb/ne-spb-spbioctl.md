# SpbIoctl enumeration

## Description

Defines values to indicate the type I/O control request.

## Constants

### `IOCTL_SPB_LOCK_CONTROLLER`

The [IOCTL_SPB_LOCK_CONTROLLER](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_lock_controller-control-code) control code is used by a client (peripheral driver) to lock the SPB controller. While the controller is locked, the client has exclusive use of the bus to access the specified target device for the lock.

### `IOCTL_SPB_UNLOCK_CONTROLLER`

The [IOCTL_SPB_UNLOCK_CONTROLLER](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_unlock_controller-control-code) I/O control code is used by a client (peripheral driver) to unlock the SPB controller. The client previously locked the controller to gain exclusive use of the bus to access a target device on the bus.

### `IOCTL_SPB_EXECUTE_SEQUENCE`

The [IOCTL_SPB_EXECUTE_SEQUENCE](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_execute_sequence) I/O control code enables a client (peripheral driver) of the SPB controller driver to perform a sequence of transfers (reads and writes) as a single, atomic operation with one I/O request. The designated device on the bus is the target for all transfers in the sequence.

### `IOCTL_SPB_LOCK_CONNECTION`

The [IOCTL_SPB_LOCK_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_lock_connection-control-code) control code is used by a client (peripheral driver) to acquire the connection lock on an SPB-connected target device that is shared with another client. While a client holds the connection lock, this client has exclusive access to the device.

### `IOCTL_SPB_UNLOCK_CONNECTION`

The [IOCTL_SPB_UNLOCK_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_unlock_connection-control-code) I/O control code is used by a client (peripheral driver) to release the connection lock on an SPB-connected target device that is shared with another client. The client previously sent an [IOCTL_SPB_LOCK_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_lock_connection-control-code) request to acquire exclusive access to the device.

### `IOCTL_SPB_FULL_DUPLEX`

The [IOCTL_SPB_FULL_DUPLEX](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_full_duplex-control-code) control code is used by a client (peripheral driver) to request a full-duplex I/O operation. Full-duplex I/O operations are supported by controllers for buses such as SPI that can simultaneously read and write data.

### `IOCTL_SPB_MULTI_SPI_TRANSFER`

The **IOCTL_SPB_MULTI_SPI_TRANSFER** control code is used by a client (peripheral driver) to request a SPI I/O operation to use a multi-SPI transfer mode such as Dual or Quad SPI. Multi-SPI I/O operations are supported by controllers for SPI buses that support data transfer in Dual or Quad SPI line modes.