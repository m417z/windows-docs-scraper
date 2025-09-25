# _IO_CONTAINER_INFORMATION_CLASS enumeration

## Description

The **IO_CONTAINER_INFORMATION_CLASS** enumeration contains constants that indicate the classes of system information that a kernel-mode driver can request.

## Constants

### `IoSessionStateInformation`

Session state information. A driver uses this enumeration constant to request information about a user session.

### `IoMaxContainerInformationClass`

Specifies the maximum value in this enumeration type.

## Remarks

To request system information, a driver calls the [IoGetContainerInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetcontainerinformation) routine and sets this routine's *InformationClass* parameter to an **IO_CONTAINER_NOTIFICATION_CLASS** constant (other than **IoMaxContainerInformationClass**). Currently, **IoGetContainerInformation** supports only *InformationClass* = **IoSessionStateInformation**.

## See also

[IoGetContainerInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetcontainerinformation)