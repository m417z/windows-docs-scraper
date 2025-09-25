# PFNKSDEVICEPNPSTART callback function

## Description

An AVStream minidriver's *AVStrMiniDeviceStart* routine is called when an [IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device) request is sent for a specified device.

## Parameters

### `Device` [in]

Pointer to a [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) structure describing the device to be started.

### `Irp` [in]

Pointer to the [IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device) that was received.

### `TranslatedResourceList` [in, optional]

Pointer to a [CM_RESOURCE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_resource_list) structure that contains the translated resource list extracted from *Irp*. Equals **NULL** if *Device* has no assigned resources. Optional.

### `UntranslatedResourceList` [in, optional]

Pointer to a [CM_RESOURCE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_resource_list) structure that contains the untranslated resource list extracted from *Irp*. Equals **NULL** if the [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) member of this parameter list has no assigned resources. Optional.

## Return value

Should return STATUS_SUCCESS or the error code that was returned from the attempt to perform the operation. The start is guaranteed to succeed if the routine returns a successful status code. Do NOT return STATUS_PENDING.

## Remarks

Specify this routine's address in the **Start** member of its [KSDEVICE_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch) structure.

Typically, this routine is used by minidrivers that must evaluate assigned resources. Resource lists are extracted from *Irp* for the convenience of the minidriver. A minidriver can parse the resource list to find the interrupt assigned to the device, as well as the physical address of memory resources.

Minidrivers may use this routine to allocate context information to associate with the AVStream device. (This is similar to a minidriver under stream class using the device extension to store context information.)

Note that STATUS_PENDING is not a legal return code from this function. To perform actions in the context of a worker thread before AVStream has completed start actions such as enabling device interfaces, use a post start dispatch. See [AVStrMiniDevicePostStart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksdevice).

This routine is optional.

## See also

[CM_RESOURCE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_resource_list)

[KSDEVICE_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch)