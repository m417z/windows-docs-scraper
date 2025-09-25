# BatteryClassSystemControl function

## Description

The **BatteryClassSystemControl** routine processes WMI IRPs on behalf of a battery miniclass driver.

## Parameters

### `ClassData` [in]

Pointer to a battery class handle that was previously received from [BatteryClassInitializeDevice](https://learn.microsoft.com/windows/desktop/api/batclass/nf-batclass-batteryclassinitializedevice).

### `WmiLibContext` [in]

Pointer to a [WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wmilib/ns-wmilib-_wmilib_context) structure. The structure provides WMI registration information, and dispatch routines for driver-specific WMI request processing.

### `DeviceObject` [in]

Pointer to the driver's device object.

### `Irp` [in, out]

Pointer to the IRP that contains the WMI request.

### `Disposition` [out]

Pointer to a memory location that the routine uses to return information about how it handled the IRP. See [WmiSystemControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wmilib/nf-wmilib-wmisystemcontrol) for a description of the possible values returned.

## Return value

**BatteryClassSystemControl** returns STATUS_SUCCESS on success, and the appropriate error code on failure.

## Remarks

Battery miniclass drivers must call this routine instead of [WmiSystemControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wmilib/nf-wmilib-wmisystemcontrol). It provides the same functionality as **WmiSystemControl**, but it also ensures that the driver registers the WMI classes that the battery class driver handles on behalf of the miniclass driver.

A battery miniclass driver's [DpWmiQueryDataBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wmilib/nc-wmilib-wmi_query_datablock_callback) routine, which is specified by the **QueryWmiDataBlock** member of [WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wmilib/ns-wmilib-_wmilib_context), must call the [BatteryClassQueryWmiDataBlock](https://learn.microsoft.com/windows/desktop/api/batclass/nf-batclass-batteryclassquerywmidatablock) routine to allow the battery class driver to process the query for the WMI classes it handles on behalf of the miniclass driver.

## See also

[BatteryClassQueryWmiDataBlock](https://learn.microsoft.com/windows/desktop/api/batclass/nf-batclass-batteryclassquerywmidatablock)

[DpWmiQueryDataBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wmilib/nc-wmilib-wmi_query_datablock_callback)

[WMILIB_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wmilib/ns-wmilib-_wmilib_context)