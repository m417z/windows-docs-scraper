# IViewHelper::SetActiveTopology

## Description

The **SetActiveTopology** method sets up the topology to be used by a Video Present Network (VidPN) on a particular graphics adapter.

## Parameters

### `wszAdaptorName` [in]

[in] A NULL-terminated string that indicates the name of the adapter to set up the topology on. The adapter name is obtained from the **DeviceKey** member of the DISPLAY_DEVICE structure. The adapter name is set in and returned from a call to the **EnumDisplayDevices** function. For more information about DISPLAY_DEVICE and **EnumDisplayDevices**, see the Microsoft Windows SDK documentation.

### `ulSourceID` [in]

[in] A ULONG that is set to the source identifier for the display configuration that **SetActiveTopology** sets.

### `ulCount` [in]

[in] A ULONG that contains the number of active target entries in the array that *pulTargetID* specifies.

### `pulTargetID` [in]

[in] An array of identifiers for the active targets.

## Return value

The **SetActiveTopology** method returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | **SetActiveTopology** successfully set up the topology. |
| **E_POINTER** | The pointer parameter (*pulTargetID*) is set to **NULL** when it should not be set to **NULL**. |
| **ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE** | The source identifier that is specified in the *ulSourceID* parameter is invalid. |
| **ERROR_GRAPHICS_INVALID_DISPLAY_ADAPTER** | **SetActiveTopology** could not match the adapter name in the *wszAdaptorName* string to an existing graphics adapter's name. |
| **ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET** | One or more of the targets that are identified by the entries in the array that *pulTargetID* specifies are invalid. |
| **ERROR_GRAPHICS_PATH_NOT_IN_TOPOLOGY** | The VidPN cannot establish the topology. |
| **Any other error code (that is defined in *Winerror.h*) will cause TMM to not restore connections.** |  |

## Remarks

**SetActiveTopology** uses the data that was received from a previous call to the [IViewHelper::GetActiveTopology](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff568169(v=vs.85)) method.

For the topology that the **SetActiveTopology** parameters specify to take affect, the VidPN must be invalidated through a call to the [IViewHelper::Commit](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff568167(v=vs.85)) method.

**SetActiveTopology** is used only when a display configuration that cannot be established through a call to the Win32 **ChangeDisplaySettingsEx** function must be set. For example, for clone view on a graphics adapter, the adapter name is the string that was obtained from the **DeviceKey** member of the DISPLAY_DEVICE structure in a call to the **EnumDisplayDevices** function. For more information about **ChangeDisplaySettingsEx**, DISPLAY_DEVICE, and **EnumDisplayDevices**, see the Windows SDK documentation.

## See also

[IViewHelper::Commit](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff568167(v=vs.85))

[IViewHelper::GetActiveTopology](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff568169(v=vs.85))