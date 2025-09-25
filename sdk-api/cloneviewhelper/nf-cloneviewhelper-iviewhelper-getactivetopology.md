# IViewHelper::GetActiveTopology

## Description

The **GetActiveTopology** method retrieves, for a given adapter, an array of identifiers for targets that are active on a given source.

## Parameters

### `wszAdaptorName` [in]

[in] A NULL-terminated string that indicates the name of the adapter to retrieve identifiers for. The adapter name is obtained from the **DeviceKey** member of the DISPLAY_DEVICE structure. The adapter name was set in and returned from a call to the **EnumDisplayDevices** function. For more information about DISPLAY_DEVICE and **EnumDisplayDevices**, see the Microsoft Windows SDK documentation.

### `ulSourceID` [in]

[in] A ULONG that is set to the source identifier whose configuration **GetActiveTopology** retrieves.

### `pulCount` [in, out]

[in,out] A pointer to a variable that receives the number of active target entries in the array that will be subsequently returned in the buffer that *pulTargetID* points to. For more information about how array entries are retrieved, see the Remarks section.

### `pulTargetID` [in, out]

[in,out] A pointer to a buffer that receives the array of identifiers for the active targets.

## Return value

The **GetActiveTopology** method returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | **GetActiveTopology** successfully retrieved identifiers. |
| **E_POINTER** | One or more of the pointer parameters is set to **NULL** when it should not be set to **NULL**. |
| **ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE** | The source identifier that is specified in the *ulSourceID* parameter is invalid. |
| **ERROR_GRAPHICS_INVALID_DISPLAY_ADAPTER** | **GetActiveTopology** could not match the adapter name in the *wszAdaptorName* string to an existing graphics adapter's name. |
| **ERROR_GRAPHICS_OPM_PARAMETER_ARRAY_TOO_SMALL** | The array that was passed in the *pulTargetID* parameter cannot hold all of the data that **GetActiveTopology** must insert. TMM will then query for the number of array elements again. |
| **Any other error code (that is defined in *Winerror.h*) will cause TMM to not act on the retrieved data.** |  |

## Remarks

**GetActiveTopology** is used to record the configuration that TMM will subsequently use in a call to the [IViewHelper::SetActiveTopology](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff568174(v=vs.85)) method to restore the configuration.

For a given source identifier and adapter name, TMM calls **GetActiveTopology** twice. In the first call to **GetActiveTopology** , the *pulTargetID* parameter is set to **NULL**, and the number of entries in the array of active target identifiers is retrieved in the variable that the *pulCount* parameter points to. In the second call to **GetActiveTopology**, the number of entries that was retrieved in the first call is passed in the variable that *pulCount* points to, and an allocated array is passed to *pulTargetID*. This allocated array receives the identifiers of the active targets.

TMM calls **GetActiveTopology** to record the display configuration that TMM will then use to reestablish the display configuration at a later time if a call to the Win32 **ChangeDisplaySettingsEx** function alone is not sufficient. For example, if a graphics adapter is set with two or more targets that are mapped to the same source (that is, clone view), the adapter name is the string that was obtained from the **DeviceKey** member of the DISPLAY_DEVICE structure in a call to the **EnumDisplayDevices** function. For more information about **ChangeDisplaySettingsEx**, DISPLAY_DEVICE, and **EnumDisplayDevices**, see the Windows SDK documentation.

## See also

[IViewHelper::SetActiveTopology](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff568174(v=vs.85))