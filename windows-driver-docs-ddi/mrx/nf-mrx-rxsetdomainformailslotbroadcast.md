# RxSetDomainForMailslotBroadcast function

## Description

**RxSetDomainForMailslotBroadcast** is called by a network mini-redirector driver to set the domain used for mailslot broadcasts if mailslots are supported by the driver.

## Parameters

### `DomainName` [in]

A pointer to a buffer that contains a zero-terminated Unicode string that names the domain to use for mailslots.

## Return value

**RxSetDomainForMailslotBroadcast** returns STATUS_SUCCESS on success or one of the following error values on failure:

| Return code | Description |
| ----------- | ----------- |
| STATUS_INSUFFICIENT_RESOURCES | There were insufficient resources to complete this routine. The memory allocation request failed for nonpaged pool memory to store the domain name. |

## Remarks

A network mini-redirector registers with RDBSS whenever the driver is loaded by the kernel and unregisters with RDBSS when the driver is unloaded. This registration process is a two-way hand shake in which the network mini-redirector informs RDBSS that it has been loaded by calling **RxRegisterMinirdr**, the registration routine exported from RDBSS. RDBSS completes the registration and initialization process by calling **MrxStart**, one of the callback routines exported by the network mini-redirector and passed in as part of the dispatch table to **RxRegisterMinirdr**.

One of the parameters passed to the **RxRegisterMinirdr** routine indicates whether the network mini-redirector supports mailslots. A network mini-redirector would normally call **RxSetDomainForMailslotBroadcast** from the **MrxStart** routine or as part of an external request to start the driver initiated by a file system control (FSCTRL) or an I/O control (IOCTL) request from a user-mode application or service.

## See also

[**IoCreateDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice)

[**RxRegisterMinirdr**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-rxregisterminirdr)

[**RxStartMinirdr**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-rxstartminirdr)

[**RxStopMinirdr**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-rxstopminirdr)

[**RxFillAndInstallFastIoDispatch**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-__rxfillandinstallfastiodispatch)