# BatteryClassInitializeDevice function

## Description

The **BatteryClassInitializeDevice** routine initializes a new battery device for the class driver.

## Parameters

### `MiniportInfo` [in]

Pointer to a [BATTERY_MINIPORT_INFO](https://learn.microsoft.com/windows/desktop/api/batclass/ns-batclass-battery_miniport_info) structure.

### `ClassData` [out]

Pointer to a location at which **BatteryClassInitializeDevice** returns a handle to be used in subsequent calls to [BatteryMiniXxx](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/_battery/) routines.

## Return value

**BatteryClassInitializeDevice** returns STATUS_SUCCESS or, possibly, STATUS_INSUFFICIENT_RESOURCES if not enough memory is available to store the battery miniclass data.

## Remarks

Battery miniclass drivers must call **BatteryClassInitializeDevice** to register each battery device and to pass data about the device and the miniclass driver to the battery class driver.

This routine should be called as part of the device initialization, typically from the miniclass driver's [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nc-wdm-driver_add_device) routine.

The **Context** member of the [BATTERY_MINIPORT_INFO](https://learn.microsoft.com/windows/desktop/api/batclass/ns-batclass-battery_miniport_info) structure points to an area where the class and miniclass drivers maintain information about the battery device and its drivers. The context area typically contains the pageable device extension from the FDO and can also include other information at the discretion of the driver writer.

The class driver passes a pointer to the context area in calls to [battery miniclass driver routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/_battery/) (BatteryMini*Xxx* routines). In their BatteryMini*Xxx* routines, miniclass drivers should read and write the device extension data through the passed-in pointer.

Miniclass drivers must use the [BATTERY_MINIPORT_INFO](https://learn.microsoft.com/windows/desktop/api/batclass/ns-batclass-battery_miniport_info) structure to supply entry points for all the [BatteryMiniXxx](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/_battery/) routines.

If **BatteryClassInitializeDevice** successfully initializes the battery device, the caller is responsible for calling the [BatteryClassUnload](https://learn.microsoft.com/windows/desktop/api/batclass/nf-batclass-batteryclassunload) function to free the resources for the battery device when it is no longer in use.

## See also

[BatteryClassUnload](https://learn.microsoft.com/windows/desktop/api/batclass/nf-batclass-batteryclassunload)

[BatteryMiniDisableStatusNotify](https://learn.microsoft.com/windows/desktop/api/batclass/nc-batclass-bclass_disable_status_notify_callback)

[BatteryMiniQueryInformation](https://learn.microsoft.com/windows/desktop/api/batclass/nc-batclass-bclass_query_information_callback)

[BatteryMiniQueryStatus](https://learn.microsoft.com/windows/desktop/api/batclass/nc-batclass-bclass_query_status_callback)

[BatteryMiniQueryTag](https://learn.microsoft.com/windows/desktop/api/batclass/nc-batclass-bclass_query_tag_callback)

[BatteryMiniSetInformation](https://learn.microsoft.com/windows/desktop/api/batclass/nc-batclass-bclass_set_information_callback)

[BatteryMiniSetStatusNotify](https://learn.microsoft.com/windows/desktop/api/batclass/nc-batclass-bclass_set_status_notify_callback)