# QueryDisplayConfig function

## Description

The **QueryDisplayConfig** function retrieves information about all possible display paths for all display devices, or views, in the current setting.

## Parameters

### `flags` [in]

The type of information to retrieve. The value for the *Flags* parameter must use one of the following values.

| Value | Meaning |
| --- | --- |
| **QDC_ALL_PATHS**<br><br>0x00000001 | Returns all the possible path combinations of sources to targets.<br><br>> [!NOTE] > In the case of any temporary modes, the QDC_ALL_PATHS setting means the mode data returned may not be the same as that which is stored in the persistence database.<br><br>> [!NOTE] > This flag may be very expensive to compute. It's not recommended to use this flag unless the caller is trying to determine the set of valid connections between sources and targets. |
| **QDC_ONLY_ACTIVE_PATHS**<br><br>0x00000002 | Returns currently active paths only. <br><br>> [!NOTE] > In the case of any temporary modes, the QDC_ONLY_ACTIVE_PATHS setting means the mode data returned may not be the same as that which is stored in the persistence database. |
| **QDC_DATABASE_CURRENT**<br><br>0x00000004 | Returns active paths as defined in the CCD database for the currently connected displays. |

The _Flags_ parameter may also be bitwise OR'ed with zero or more of the following values.

| Value | Meaning |
| --- | --- |
| **QDC_VIRTUAL_MODE_AWARE**<br><br>0x00000010 | This flag should be bitwise OR'ed with other flags to indicate that the caller is aware of virtual mode support.<br><br>Supported starting in Windows 10. |
| **QDC_INCLUDE_HMD**<br><br>0x00000020 | This flag should be bitwise OR'ed with QDC_ONLY_ACTIVE_PATHS to indicate that the caller would like to include head-mounted displays (HMDs) in the list of active paths. See Remarks for more information.<br><br>Supported starting in Windows 10 1703 Creators Update. |
| **QDC_VIRTUAL_REFRESH_RATE_AWARE**<br><br>0x00000040 | This flag should be bitwise OR'ed with other flags to indicate that the caller is aware of virtual refresh rate support.<br><br>Supported starting in Windows 11. |

### `numPathArrayElements` [in, out]

Pointer to a variable that contains the number of elements in *pPathInfoArray*. This parameter cannot be **NULL**. If **QueryDisplayConfig** returns ERROR_SUCCESS, *pNumPathInfoElements* is updated with the number of valid entries in *pPathInfoArray*.

### `pathArray` [out]

Pointer to a variable that contains an array of [DISPLAYCONFIG_PATH_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_path_info) elements. Each element in *pPathInfoArray* describes a single path from a source to a target. The source and target mode information indexes are only valid in combination with the *pmodeInfoArray* tables that are returned for the API at the same time. This parameter cannot be **NULL**. The *pPathInfoArray* is always returned in path priority order. For more information about path priority order, see [Path Priority Order](https://learn.microsoft.com/windows-hardware/drivers/display/path-priority-order).

### `numModeInfoArrayElements` [in, out]

Pointer to a variable that specifies the number in element of the mode information table. This parameter cannot be **NULL**. If **QueryDisplayConfig** returns ERROR_SUCCESS, *pNumModeInfoArrayElements* is updated with the number of valid entries in *pModeInfoArray*.

### `modeInfoArray` [out]

Pointer to a variable that contains an array of [DISPLAYCONFIG_MODE_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_mode_info) elements. This parameter cannot be **NULL**.

### `currentTopologyId` [out, optional]

Pointer to a variable that receives the identifier of the currently active topology in the CCD database. For a list of possible values, see the [DISPLAYCONFIG_TOPOLOGY_ID](https://learn.microsoft.com/windows/desktop/api/wingdi/ne-wingdi-displayconfig_topology_id) enumerated type.

The *pCurrentTopologyId* parameter is only set when the *Flags* parameter value is QDC_DATABASE_CURRENT.

If the *Flags* parameter value is set to QDC_DATABASE_CURRENT, the *pCurrentTopologyId* parameter must not be **NULL**. If the *Flags* parameter value is not set to QDC_DATABASE_CURRENT, the *pCurrentTopologyId* parameter value must be **NULL**.

## Return value

The function returns one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function succeeded. |
| **ERROR_INVALID_PARAMETER** | The combination of parameters and flags that are specified is invalid. |
| **ERROR_NOT_SUPPORTED** | The system is not running a graphics driver that was written according to the [Windows Display Driver Model (WDDM)](https://learn.microsoft.com/windows-hardware/drivers/display/windows-vista-display-driver-model-design-guide). The function is only supported on a system with a WDDM driver running. |
| **ERROR_ACCESS_DENIED** | The caller does not have access to the console session. This error occurs if the calling process does not have access to the current desktop or is running on a remote session. |
| **ERROR_GEN_FAILURE** | An unspecified error occurred. |
| **ERROR_INSUFFICIENT_BUFFER** | The supplied path and mode buffer are too small. |

## Remarks

As the [GetDisplayConfigBufferSizes](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdisplayconfigbuffersizes) function can only determine the required array size at a particular moment in time, it is possible that between calls to **GetDisplayConfigBufferSizes** and **QueryDisplayConfig** the system configuration will change and the provided array sizes will no longer be sufficient to store the new path data. In this situation, **QueryDisplayConfig** fails with ERROR_INSUFFICIENT_BUFFER, and the caller should call **GetDisplayConfigBufferSizes** again to get the new array sizes. The caller should then allocate the correct amount of memory.

**QueryDisplayConfig** returns paths in the path array that the *pPathInfoArray* parameter specifies and the source and target modes in the mode array that the *pModeInfoArray* parameter specifies. **QueryDisplayConfig** always returns paths in path priority order. If QDC_ALL_PATHS is set in the *Flags* parameter, **QueryDisplayConfig** returns all the inactive paths after the active paths.

Full path, source mode, and target mode information is available for all active paths. The **ModeInfoIdx** members in the [DISPLAYCONFIG_PATH_SOURCE_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_path_source_info) and [DISPLAYCONFIG_PATH_TARGET_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_path_target_info) structures for the source and target are set up for these active paths. For inactive paths, returned source and target mode information is not available; therefore, the target information in the path structure is set to default values, and the source and target mode indexes are marked as invalid. For database queries, if the current connect monitors have an entry, **QueryDisplayConfig** returns full path, source mode, and target mode information (same as for active paths). However, if the database does not have a entry, **QueryDisplayConfig** returns just the path information with the default target details (same as for inactive paths).

For an example of how source and target mode information relates to path information, see [Relationship of Mode Information to Path Information](https://learn.microsoft.com/windows-hardware/drivers/display/relationship-of-mode-information-to-path-information).

The caller can use [DisplayConfigGetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-displayconfiggetdeviceinfo) to obtain additional information about the source or target device, for example, the monitor names and monitor preferred mode and source device name.

If a target is currently being force projected, the **statusFlags** member of the [DISPLAYCONFIG_PATH_TARGET_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_path_target_info) structure has one of the DISPLAYCONFIG_TARGET_FORCED_XXX flags set.

If the QDC_DATABASE_CURRENT flag is set in the *Flags* parameter, **QueryDisplayConfig** returns the topology identifier of the active database topology in the variable that the *pCurrentTopologyId* parameter points to. If the QDC_ALL_PATHS or QDC_ONLY_ACTIVE_PATHS flag is set in the *Flags* parameter, the *pCurrentTopologyId* parameter must be set to **NULL**; otherwise, **QueryDisplayConfig** returns ERROR_INVALID_PARAMETER.

If a caller calls **QueryDisplayConfig** with the QDC_DATABASE_CURRENT flag set in the *Flags* parameter, **QueryDisplayConfig** initializes the [DISPLAYCONFIG_2DREGION](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_2dregion) structure that is specified in the **totalSize** member of the [DISPLAYCONFIG_VIDEO_SIGNAL_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_video_signal_info) structure to zeros and does not complete DISPLAYCONFIG_2DREGION.

The DEVMODE structure that is returned by the [EnumDisplaySettings](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaysettingsa) Win32 function (described in the Windows SDK documentation) contains information that relates to both the source and target modes. However, the [CCD APIs](https://learn.microsoft.com/windows-hardware/drivers/display/ccd-apis) explicitly separate the source and target mode components.

### Head-mounted and specialized monitors

__QueryDisplayConfig__ and many other Win32 display APIs have limited awareness of head-mounted and specialized monitors, since those displays do not participate in the Windows desktop environment. However, there are scenarios where it's necessary to understand the connectivity of these displays (e.g. content protection scenarios). For these limited scenarios, `(QDC_INCLUDE_HMD | QDC_ONLY_ACTIVE_PATHS)` can be used to discover the connectivity of head-mounted displays. These paths will be marked with the the DISPLAYCONFIG_TARGET_IS_HMD flag in the [DISPLAYCONFIG_PATH_TARGET_INFO.statusFlags](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-displayconfig_path_target_info) field. This support was added in the Windows 10 1703 Creators Update.

### DPI virtualization
This API does not participate in DPI virtualization. All sizes in the DEVMODE structure are in terms of physical pixels, and are not related to the calling context.

## Examples

The following example enumerates active display paths with __QueryDisplayConfig__ and __GetDisplayConfigBufferSizes__ and prints out data for each path using __DisplayConfigGetDeviceInfo__.

```cpp
#include <windows.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    vector<DISPLAYCONFIG_PATH_INFO> paths;
    vector<DISPLAYCONFIG_MODE_INFO> modes;
    UINT32 flags = QDC_ONLY_ACTIVE_PATHS | QDC_VIRTUAL_MODE_AWARE;
    LONG result = ERROR_SUCCESS;

    do
    {
        // Determine how many path and mode structures to allocate
        UINT32 pathCount, modeCount;
        result = GetDisplayConfigBufferSizes(flags, &pathCount, &modeCount);

        if (result != ERROR_SUCCESS)
        {
            return HRESULT_FROM_WIN32(result);
        }

        // Allocate the path and mode arrays
        paths.resize(pathCount);
        modes.resize(modeCount);

        // Get all active paths and their modes
        result = QueryDisplayConfig(flags, &pathCount, paths.data(), &modeCount, modes.data(), nullptr);

        // The function may have returned fewer paths/modes than estimated
        paths.resize(pathCount);
        modes.resize(modeCount);

        // It's possible that between the call to GetDisplayConfigBufferSizes and QueryDisplayConfig
        // that the display state changed, so loop on the case of ERROR_INSUFFICIENT_BUFFER.
    } while (result == ERROR_INSUFFICIENT_BUFFER);

    if (result != ERROR_SUCCESS)
    {
        return HRESULT_FROM_WIN32(result);
    }

    // For each active path
    for (auto& path : paths)
    {
        // Find the target (monitor) friendly name
        DISPLAYCONFIG_TARGET_DEVICE_NAME targetName = {};
        targetName.header.adapterId = path.targetInfo.adapterId;
        targetName.header.id = path.targetInfo.id;
        targetName.header.type = DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_NAME;
        targetName.header.size = sizeof(targetName);
        result = DisplayConfigGetDeviceInfo(&targetName.header);

        if (result != ERROR_SUCCESS)
        {
            return HRESULT_FROM_WIN32(result);
        }

        // Find the adapter device name
        DISPLAYCONFIG_ADAPTER_NAME adapterName = {};
        adapterName.header.adapterId = path.targetInfo.adapterId;
        adapterName.header.type = DISPLAYCONFIG_DEVICE_INFO_GET_ADAPTER_NAME;
        adapterName.header.size = sizeof(adapterName);

        result = DisplayConfigGetDeviceInfo(&adapterName.header);

        if (result != ERROR_SUCCESS)
        {
            return HRESULT_FROM_WIN32(result);
        }

        wcout
            << L"Monitor with name "
            << (targetName.flags.friendlyNameFromEdid ? targetName.monitorFriendlyDeviceName : L"Unknown")
            << L" is connected to adapter "
            << adapterName.adapterDevicePath
            << L" on target "
            << path.targetInfo.id
            << L"\n";
    }
}
```

## See also

[DISPLAYCONFIG_MODE_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_mode_info)

[DISPLAYCONFIG_PATH_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_path_info)

[DISPLAYCONFIG_PATH_SOURCE_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_path_source_info)

[DISPLAYCONFIG_PATH_TARGET_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_path_target_info)

[DISPLAYCONFIG_TOPOLOGY_ID](https://learn.microsoft.com/windows/desktop/api/wingdi/ne-wingdi-displayconfig_topology_id)

[DisplayConfigGetDeviceInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-displayconfiggetdeviceinfo)

[SetDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdisplayconfig)