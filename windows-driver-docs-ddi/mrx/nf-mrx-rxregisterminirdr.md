# RxRegisterMinirdr function

## Description

**RxRegisterMinirdr** is called by a network mini-redirector driver to register the driver with RDBSS, which adds the registration information to an internal registration table. RDBSS also builds a device object for the network mini-redirector.

## Parameters

### `DeviceObject` [out]

A pointer to where the created device object will be stored.

### `DriverObject` [in, out]

A pointer to the driver object of the network mini-redirector driver. Each driver receives a pointer to its driver object in a parameter to its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine. This driver object will be used to create the device object for the network mini-redirector driver.

### `MrdrDispatch` [in]

A pointer to the dispatch table for the network mini-redirector. This dispatch table includes configuration information for the network mini-redirector and a table of pointers to callback routines implemented by the network mini-redirector kernel driver. RDBSS makes calls to the network mini-redirector driver through this list of callback routines.

### `Controls` [in]

The set of options that determine capabilities of the network mini-redirector driver and how RDBSS should handle initialization and name table caching for the network mini-redirector driver. These options can include any combination of the following bits:

#### RX_REGISTERMINI_FLAG_DONT_PROVIDE_UNCS

When this flag is set, it indicates that the network mini-redirector does not support UNC names.

#### RX_REGISTERMINI_FLAG_DONT_PROVIDE_MAILSLOTS

When this flag is set, it indicates that the network mini-redirector does not support mailslots.

#### RX_REGISTERMINI_FLAG_DONT_INIT_DRIVER_DISPATCH

When this flag is set, it indicates that the network mini-redirector does not want RDBSS to initialize the driver dispatch entry points of the mini-redirector driver to point to RDBSS internal routines. This option would only be used in unusual circumstances. Normally RDBSS would set the driver dispatch entry points and the fast I/O dispatch in the network mini-redirector driver object to point to routines internal to RDBSS.

#### RX_REGISTERMINI_FLAG_DONT_INIT_PREFIX_N_SCAVENGER

When this flag is set, it indicates that the network mini-redirector does not want RDBSS to initialize its internal network name table and scavenger data structures for scavenging this name table. This option would be set for a network mini-redirector that wants to handle caching for network share names itself and not use the RDBSS facilities for name caching and scavenging.

### `DeviceName` [in]

A pointer to a buffer that contains a zero-terminated Unicode string that names the device object. The string must be a full path name. This parameter is passed as *DeviceName* to the **IoCreateDevice** routine by RDBSS.

### `DeviceExtensionSize` [in]

The size specified by the mini-redirector driver for the number of bytes to be allocated for the device extension of the device object. The internal structure of the device extension is driver-defined. This parameter is added to the size of the device extension used by RDBSS and passed as the *DeviceExtensionSize* parameter to the [IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice) routine by RDBSS.

### `DeviceType` [in]

The device type used when the device object is created. This specifies one of the system-defined FILE_DEVICE_XXX constants that indicate the type of device or a vendor-defined value for a new type of device. This value would normally be FILE_DEVICE_NETWORK_FILE_SYSTEM for network mini-redirector drivers. This parameter is passed as *DeviceType* to the **IoCreateDevice** routine by RDBSS.

### `DeviceCharacteristics` [in]

The device characteristics used when the device object is created. This specifies one or more system-defined constants, combined together, that provide additional information about the driver's device. This value must include FILE_REMOTE_DEVICE for network mini-redirector drivers, but this might be combined with other characteristics such as FILE_DEVICE_SECURE_OPEN. This parameter is passed as *DeviceCharacteristics* to the **IoCreateDevice** routine by RDBSS.

## Return value

**RxRegisterMinirdr** returns STATUS_SUCCESS on success or one of the following error values on failure:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | There were insufficient resources to create the device object. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the routine. This error will be returned if the *DeviceObject* parameter is a **NULL** pointer. |
| **STATUS_OBJECT_NAME_COLLISION** | A name collision occurred when trying to create this device object. |
| **STATUS_OBJECT_NAME_EXISTS** | A device object with this name already exists. |
| **STATUS_UNSUCCESSFUL** | The call to create the device object returned a **NULL** device object. |

## Remarks

A network mini-redirector registers with RDBSS whenever the driver is loaded by the kernel and unregisters with RDBSS when the driver is unloaded. A non-monolithic driver (the SMB network mini-redirector) communicates with the *Rdbss.sys*, another kernel driver. For a monolithic network mini-redirector driver that statically links with *Rdbsslib.lib*, this communication is merely a call to an *Rdbsslib.lib* library routine.

A network mini-redirector informs RDBSS that it has been loaded by calling **RxRegisterMinirdr**, the registration routine exported from RDBSS. When a network mini-redirector driver first starts (in its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine), the driver calls the RDBSS **RxRegisterMinirdr** routine to register the network mini-redirector driver with RDBSS. Based on the parameters passed to **RxRegisterMinirdr**, RDBSS calls [IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice) to create the device object for the network mini-redirector driver.

As part of this registration process, the network mini-redirector passes a parameter to **RxRegisterMinirdr** that is a pointer to a large structure, MINIRDR_DISPATCH, which contains configuration information for the network mini-redirector and a dispatch table of pointers to callback routines implemented by the network mini-redirector driver. This configuration data is used to configure internal RDBSS tables for use with this network mini-redirector. RDBSS uses the callback routines passed in this structure to communicate with the network mini-redirector. A network mini-redirector can chose to implement only some of these callback routines. Any callback routine that is not implemented should be set to a **NULL** pointer in the dispatch table passed to RDBSS. Only callback routines implemented by the network mini-redirector will be called by RDBSS.

Note that the **RxRegisterMinirdr** routine sets all of the driver dispatch routines of the network mini-redirector driver to point to the top-level RDBSS dispatch routine, **RxFsdDispatch**. A network mini-redirector can override this behavior by saving a copy of its driver dispatch entry points, calling **RxRegisterMinirdr**, and rewriting the driver dispatch with its own entry points after the call to **RxRegisterMinirdr** returns. A network mini-redirector can also prevent its driver dispatch routines from being copied over by the **RxRegisterMinirdr** routine if the RX_REGISTERMINI_FLAG_DONT_INIT_DRIVER_DISPATCH bit is set in the *Controls* parameter.

If the **RxRegisterMinirdr** call is successful, a number of members in RDBSS_DEVICE_OBJECT pointed to by the *DeviceObject* parameter are initialized including the following:

* The **Dispatch** member is set to the *MrdrDispatch* parameter.
* The **RegistrationControls** member is set to the *Controls* parameter.
* The **DeviceName** member is set to the *DeviceName* parameter.
* The **RegisterUncProvider** member is set to **TRUE** if the RX_REGISTERMINI_FLAG_DONT_PROVIDE_UNCS bit in the *Controls* parameter was not set.
* The **RegisterMailSlotProvider** member is set to **TRUE** if the RX_REGISTERMINI_FLAG_DONT_PROVIDE_MAILSLOTS bit in the *Controls* parameter was not set.
* The **NetworkProviderPriority** member is set to the network provider priority that MUP will use.

If the **RxRegisterMinirdr** call is successful and the RX_REGISTERMINI_FLAG_DONT_INIT_PREFIX_N_SCAVENGER bit in the *Controls* parameter is not set, a number of other members in RDBSS_DEVICE_OBJECT pointed to by the *DeviceObject* parameter are initialized, including the following:

* The **pRxNetNameTable** member structure is initialized.
* The **RxNetNameTableInDeviceObject.IsNetNameTable** member is set to **TRUE**.
* The **pRdbssScavenger** member structure is initialized.

If the **RxRegisterMinirdr** call is successful, RDBSS sets the internal state of the network mini-redirector in RDBSS to RDBSS_STARTABLE.

The network mini-redirector does not actually start operation until it receives a call to its [MRxStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_calldown_ctx) routine, one of the callback routines passed in the MINIRDR_DISPATCH structure. The **MrxStart** callback routine must be implemented by the network mini-redirector driver if it wishes to receive callbacks for operations, unless the network mini-redirector preserves its own driver dispatch entry points. Otherwise, RDBSS will only allow the following I/O request packets through to the driver until **MrxStart** returns successfully:

* IRP requests for device create operations and device operations where the *FileObject->FileName.Length* parameter on the IRPSP is zero and the *FileObject->RelatedFileObject* parameter is **NULL**.

For any other IRP request, the RDBSS dispatch routine, [RxFsdDispatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-rxfsddispatch), will return a status of STATUS_REDIRECTOR_NOT_STARTED.

The RDBSS dispatch routine will also fail any requests for the following I/O request packets:

* IRP_MJ_CREATE_MAILSLOT
* IRP_MJ_CREATE_NAMED_PIPE

The network mini-redirector **MrxStart** routine is called by RDBSS when the **RxStartMiniRdr** routine is called. The RDBSS **RxStartMinirdr** is usually called as a result of an FSCTL or IOCTL request from a user-mode application or service to start the network mini-redirector. The call to **RxStartMinirdr** cannot be made from the **DriverEntry** routine of the network mini-redirector after a successful call to **RxRegisterMinirdr** because some of the start processing requires that the driver initialization be completed. Once the **RxStartMinirdr** call is received, RDBSS completes the start process by calling the **MrxStart** routine of the network mini-redirector. If the call to **MrxStart** returns success, RDBSS sets the internal state of the mini-redirector in RDBSS to RDBSS_STARTED.

## See also

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice)

[MRxStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_calldown_ctx)

[RxFsdDispatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-rxfsddispatch)

[RxSetDomainForMailslotBroadcast](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-rxsetdomainformailslotbroadcast)

[RxStartMinirdr](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-rxstartminirdr)

[RxStopMinirdr](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-rxstopminirdr)

[RxUnregisterMinirdr](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxstruc/nf-rxstruc-rxunregisterminirdr)

[RxpUnregisterMinirdr](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-rxpunregisterminirdr)

[__RxFillAndInstallFastIoDispatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nf-mrx-__rxfillandinstallfastiodispatch)