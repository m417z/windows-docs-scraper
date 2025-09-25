# IViewHelper::GetConnectedIDs

## Description

The **GetConnectedIDs** method retrieves, for a given adapter, an array of identifiers for either targets or sources.

## Parameters

### `wszAdaptorName` [in]

[in] A NULL-terminated string that indicates the name of the adapter to retrieve identifiers for. The adapter name is obtained from the **DeviceKey** member of the DISPLAY_DEVICE structure. The adapter name was set in and returned from a call to the **EnumDisplayDevices** function. For more information about DISPLAY_DEVICE and **EnumDisplayDevices**, see the Microsoft Windows SDK documentation.

### `pulCount` [in, out]

[in,out] A pointer to a variable that receives the number of entries in the array that will be subsequently returned in the buffer that *pulID* points to. For more information about how array entries are retrieved, see the Remarks section.

### `pulID` [in, out]

[in,out] A pointer to a buffer that receives the array of identifiers for the targets or sources.

### `ulFlags` [in]

[in] A flag value that identifies the type of identifiers to retrieve. *ulFlags* can be set to one of the following values.

| Value | Meaning |
| --- | --- |
| GETCONNECTEDIDS_TARGET (0) | The array that the *pulID* parameter points to should contain connected (though not necessarily active) targets. |
| GETCONNECTEDIDS_SOURCE (1) | The array that *pulID* points to should contain available sources. |

## Return value

The **GetConnectedIDs** method returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | **GetConnectedIDs** successfully retrieved identifiers. |
| **E_INVALIDARG** | The *ulFlags* parameter contained an unknown value. |
| **E_POINTER** | One or more of the pointer parameters is set to **NULL** when it should not be set to **NULL**. |
| **ERROR_GRAPHICS_INVALID_DISPLAY_ADAPTER** | **GetConnectedIDs** could not match the adapter name in the *wszAdaptorName* string to an existing graphics adapter's name. |
| **ERROR_GRAPHICS_OPM_PARAMETER_ARRAY_TOO_SMALL** | The array that was passed in the *pulID* parameter cannot hold all of the data that **GetConnectedIDs** must insert. TMM will then query for the number of array elements again. |
| **Any other error code (that is defined in *Winerror.h*) will cause TMM to not act on the retrieved data.** |  |

## Remarks

**GetConnectedIDs** is used to determine if two monitors that are connected to a graphics adapter can be placed into clone view.

 To qualify as a target, a monitor or other display device must be connected to the computer. For example, consider a graphics adapter with a Digital Video Interface (DVI) connector that supports output through DVI analog and DVI digital. **GetConnectedIDs** reports the target identifier of the DVI analog or DVI digital output connector only if a monitor is plugged into that connector. Therefore, a report of targets is not a report of all of the outputs that are available through the video ports. Rather, it is a report of what is physically attached to the graphics adapter. Each monitor is reported as a target whether the monitor is active or not.

In the first call to **GetConnectedIDs**, the *pulID*  parameter is set to **NULL**, and the number of entries in the array of identifiers is retrieved in the variable that the *pulCount* parameter points to. In the second call to **GetConnectedIDs**, the number of entries that was retrieved in the first call is passed in the variable that *pulCount* points to, and an allocated array is passed to *pulCount*. This allocated array receives the identifiers of the targets or sources.

**GetConnectedIDs** is called when a new second monitor is detected. The [IViewHelper::SetActiveTopology](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff568174(v=vs.85)) method must then be called to set the display on the adapter to clone view. The adapter name is the string that was obtained from the **DeviceKey** member of the DISPLAY_DEVICE structure in a call to the **EnumDisplayDevices** function. For more information about DISPLAY_DEVICE and **EnumDisplayDevices**, see the Windows SDK documentation.

## See also

[IViewHelper::SetActiveTopology](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff568174(v=vs.85))