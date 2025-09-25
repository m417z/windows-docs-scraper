# FltRegisterFilter function

## Description

**FltRegisterFilter** registers a minifilter driver.

## Parameters

### `Driver` [in]

A pointer to the driver object for the minifilter driver. This should be the same driver object pointer that was passed as input to the minifilter driver's **DriverEntry** routine.

### `Registration` [in]

A pointer to a caller-allocated minifilter driver registration structure ([FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration)).

### `RetFilter` [out]

A pointer to a caller-allocated variable that receives an opaque filter pointer for the caller.

## Return value

**FltRegisterFilter** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | **FltRegisterFilter** encountered a pool allocation failure. This is an error code. |
| **STATUS_INVALID_PARAMETER** | One of the following: <br><br>* The **Version** member of the *Registration* structure was not set to FLT_REGISTRATION_VERSION.<br>* One of the non-NULL name-provider routines in the *Registration* structure was set to an invalid value. The **GenerateFileNameCallback**, **NormalizeNameComponentCallback**, and **NormalizeNameComponentExCallback** members of [FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration) point to the name-provider routines.<br><br>STATUS_INVALID_PARAMETER is an error code. |
| **STATUS_FLT_NOT_INITIALIZED** | The Filter Manager was not initialized when the filter tried to register. Make sure that the Filter Manager is loaded as a driver. This is an error code. |
| **STATUS_OBJECT_NAME_NOT_FOUND** | The filter service key is not found in the registry.<br><br>-or-<br><br>The filter instance is not registered. |

## Remarks

Every minifilter driver must call **FltRegisterFilter** from its **DriverEntry** routine to add itself to the global list of registered minifilter drivers and to provide the Filter Manager with a list of callback functions and other information about the minifilter driver.

**FltRegisterFilter** returns an opaque filter pointer for the minifilter driver in **RetFilter*. This pointer value uniquely identifies the minifilter driver and remains constant as long as the minifilter driver is loaded. The minifilter driver should save this pointer, because it is a required parameter for [FltStartFiltering](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltstartfiltering) and [FltUnregisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltunregisterfilter).

After calling **FltRegisterFilter**, a minifilter driver typically calls [FltStartFiltering](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltstartfiltering) to begin filtering I/O operations.

A minifilter driver can only call **FltRegisterFilter** to register itself, not another minifilter driver.

To unregister itself, a minifilter driver calls [FltUnregisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltunregisterfilter)..

## See also

[FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration)

[FltStartFiltering](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltstartfiltering)

[FltUnregisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltunregisterfilter)