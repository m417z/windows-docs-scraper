# _MCD_INIT_DATA structure

## Description

The changer miniclass driver fills the MCD_INIT_DATA structure with pointers to its internal command processing routines and passes them to the changer class driver.

## Members

### `InitDataSize`

Size of this structure in bytes.

### `ChangerAdditionalExtensionSize`

Pointer to changer miniclass driver routine that returns the number of bytes the changer miniclass driver requires to store device-specific information in the device extension. This routine has the following prototype:

```
typedef
ULONG
(*CHANGER_EXTENSION_SIZE)(
  IN VOID
  );
```

### `ChangerInitialize`

Pointer to changer miniclass driver routine that does miniclass driver-specific initialization and readies the changer to receive other requests. This routine has the following prototype:

```
typedef
NTSTATUS
(*CHANGER_INITIALIZE)(
  IN PDEVICE_OBJECT  DeviceObject
  );
```

### `ChangerError`

Pointer to changer miniclass driver routine that does device-specific error processing. This routine has the following prototype:

```
typedef
VOID
(*CHANGER_ERROR_ROUTINE)(
  IN PDEVICE_OBJECT  DeviceObject,
  IN PSCSI_REQUEST_BLOCK  Srb,
  IN NTSTATUS  *Status,
  IN BOOLEAN  *Retry
  );
```

### `ChangerPerformDiagnostics`

Pointer to changer miniclass driver routine that performs diagnostic tests on the device. This routine has the following prototype:

```
typedef
NTSTATUS
(*CHANGER_PERFORM_DIAGNOSTICS)(
  IN PDEVICE_OBJECT  DeviceObject,
  OUT PWMI_CHANGER_PROBLEM_DEVICE_ERROR  changerDeviceError
  );
```

### `ChangerGetParameters`

Pointer to changer miniclass driver routine that handles the device-specific aspects of a device-control IRP with the IOCTL code [IOCTL_CHANGER_GET_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_get_parameters). This routine has the following prototype:

```
typedef
NTSTATUS
(*CHANGER_COMMAND_ROUTINE)(
  IN PDEVICE_OBJECT  DeviceObject,
  IN PIRP  Irp
  );
```

### `ChangerGetStatus`

Pointer to changer miniclass driver routine that handles the device-specific aspects of a device-control IRP with the IOCTL code [IOCTL_CHANGER_GET_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_get_status). This routine has the following prototype:

```
typedef
NTSTATUS
(*CHANGER_COMMAND_ROUTINE)(
  IN PDEVICE_OBJECT  DeviceObject,
  IN PIRP  Irp
  );
```

### `ChangerGetProductData`

Pointer to a changer miniclass driver routine that handles the device-specific aspects of a device-control IRP with the IOCTL code [IOCTL_CHANGER_GET_PRODUCT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_get_product_data). This routine has the following prototype:

```
typedef
NTSTATUS
(*CHANGER_COMMAND_ROUTINE)(
  IN PDEVICE_OBJECT  DeviceObject,
  IN PIRP  Irp
  );
```

### `ChangerSetAccess`

Pointer to a changer miniclass driver routine that handles the device-specific aspects of a device-control IRP with the IOCTL code [IOCTL_CHANGER_SET_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_set_access). This routine has the following prototype:

```
typedef
NTSTATUS
(*CHANGER_COMMAND_ROUTINE)(
  IN PDEVICE_OBJECT  DeviceObject,
  IN PIRP  Irp
  );
```

### `ChangerGetElementStatus`

Pointer to a changer miniclass driver routine that handles the device-specific aspects of a device-control IRP with the IOCTL code [IOCTL_CHANGER_GET_ELEMENT_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_get_element_status). This routine has the following prototype:

```
typedef
NTSTATUS
(*CHANGER_COMMAND_ROUTINE)(
  IN PDEVICE_OBJECT  DeviceObject,
  IN PIRP  Irp
  );
```

### `ChangerInitializeElementStatus`

Pointer to a changer miniclass driver routine that handles the device-specific aspects of a device-control IRP with the IOCTL code [IOCTL_CHANGER_INITIALIZE_ELEMENT_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_initialize_element_status). This routine has the following prototype:

```
typedef
NTSTATUS
(*CHANGER_COMMAND_ROUTINE)(
  IN PDEVICE_OBJECT  DeviceObject,
  IN PIRP  Irp
  );
```

### `ChangerSetPosition`

Pointer to a changer miniclass driver routine that handles the device-specific aspects of a device-control IRP with the IOCTL code [IOCTL_CHANGER_SET_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_set_position). This routine has the following prototype:

```
typedef
NTSTATUS
(*CHANGER_COMMAND_ROUTINE)(
  IN PDEVICE_OBJECT  DeviceObject,
  IN PIRP  Irp
  );
```

### `ChangerExchangeMedium`

Pointer to a changer miniclass driver routine that handles the device-specific aspects of a device-control IRP with the IOCTL code [IOCTL_CHANGER_EXCHANGE_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_exchange_medium). This routine has the following prototype:

```
typedef
NTSTATUS
(*CHANGER_COMMAND_ROUTINE)(
  IN PDEVICE_OBJECT  DeviceObject,
  IN PIRP  Irp
  );
```

### `ChangerMoveMedium`

Pointer to a changer miniclass driver routine that handles the device-specific aspects of a device-control IRP with the IOCTL code [IOCTL_CHANGER_MOVE_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_move_medium). This routine has the following prototype:

```
typedef
NTSTATUS
(*CHANGER_COMMAND_ROUTINE)(
  IN PDEVICE_OBJECT  DeviceObject,
  IN PIRP  Irp
  );
```

### `ChangerReinitializeUnit`

Pointer to a changer miniclass driver routine that handles the device-specific aspects of a device-control IRP with the IOCTL code [IOCTL_CHANGER_REINITIALIZE_TRANSPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_reinitialize_transport). This routine has the following prototype:

```
typedef
NTSTATUS
(*CHANGER_COMMAND_ROUTINE)(
  IN PDEVICE_OBJECT  DeviceObject,
  IN PIRP  Irp
  );
```

### `ChangerQueryVolumeTags`

Pointer to a changer miniclass driver routine that handles the device-specific aspects of a device-control IRP with the IOCTL code of [IOCTL_CHANGER_QUERY_VOLUME_TAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_query_volume_tags). This routine has the following prototype:

```
typedef
NTSTATUS
(*CHANGER_COMMAND_ROUTINE)(
  IN PDEVICE_OBJECT  DeviceObject,
  IN PIRP  Irp
  );
```

## Remarks

This structure is used by the changer driver in Windows XP and later operating systems only.

## See also

[ChangerAdditionalExtensionSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changeradditionalextensionsize)

[ChangerError](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changererror)

[ChangerExchangeMedium](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changerexchangemedium)

[ChangerGetElementStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changergetelementstatus)

[ChangerGetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changergetparameters)

[ChangerGetProductData](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changergetproductdata)

[ChangerGetStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changergetstatus)

[ChangerInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changerinitialize)

[ChangerInitializeElementStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changerinitializeelementstatus)

[ChangerMoveMedium](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changermovemedium)

[ChangerPerformDiagnostics](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changerperformdiagnostics)

[ChangerQueryVolumeTags](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changerqueryvolumetags)

[ChangerReinitializeUnit](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changerreinitializeunit)

[ChangerSetAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changersetaccess)

[ChangerSetPosition](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changersetposition)

[IOCTL_CHANGER_EXCHANGE_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_exchange_medium)

[IOCTL_CHANGER_GET_ELEMENT_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_get_element_status)

[IOCTL_CHANGER_GET_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_get_parameters)

[IOCTL_CHANGER_GET_PRODUCT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_get_product_data)

[IOCTL_CHANGER_GET_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_get_status)

[IOCTL_CHANGER_INITIALIZE_ELEMENT_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_initialize_element_status)

[IOCTL_CHANGER_MOVE_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_move_medium)

[IOCTL_CHANGER_SET_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_set_access)

[IOCTL_CHANGER_SET_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_set_position)