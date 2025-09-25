# ChangerClassInitialize function

## Description

The **ChangerClassInitialize** routine initializes the driver.

## Parameters

### `DriverObject` [in]

Pointer to the changer miniclass driver object. This is passed as a parameter to the miniclass driver's **DriverEntry** routine. The format of this object is operating system-specific and should not be interpreted by the miniclass driver.

### `RegistryPath` [in]

Pointer to the registry path for changer miniclass driver. This is also passed as a parameter to the miniclass driver's **DriverEntry** routine. The format of this is operating system-specific and should not be interpreted by the miniclass driver.

### `ChangerInitData`

Pointer to an [**MCD_INIT_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/ns-mcd-_mcd_init_data) structure containing miniclass driver-specific information such as the entry points for the changer miniclass driver's command processing routines.

## Return value

**ChangerClassInitialize** returns a value indicating the success or failure of the driver initialization. If initialization is successful, **ChangerClassInitialize** returns STATUS_SUCCESS. Otherwise, **ChangerClassInitialize** returns an appropriate error message. Minidrivers should *not* interpret this error value, but should just return this value from their **DriverEntry** routine.

## Remarks

**ChangerClassInitialize** is a changer class driver routine that miniclass drivers can call in Microsoft Windows XP and later operating systems.

Changer miniclass drivers call **ChangerClassInitialize** from within their **DriverEntry** routines to initialize the driver. **ChangerClassInitialize** performs many tasks formerly performed by the changer class driver's **DriverEntry** routine such as registering the miniclass driver's dispatch routines. It allocates a driver object extension and copies the data contained in *MCDInitData* into the driver object extension along with other initialization data such as the driver's registry path and pointers to certain changer class driver routines that are operating system-specific.

Changer miniclass drivers must allocate an [MCD_INIT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/ns-mcd-_mcd_init_data) structure, zero the structure by calling [RtlZeroMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlzeromemory), and then assign values to the appropriate members, before passing the structure's address to **ChangerClassInitialize** by means of the *MCDInitData* parameter.

## See also

[MCD_INIT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/ns-mcd-_mcd_init_data)

[RtlZeroMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlzeromemory)