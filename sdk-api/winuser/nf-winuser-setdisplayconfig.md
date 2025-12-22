# SetDisplayConfig function

## Description

The **SetDisplayConfig** function modifies the display topology, source, and target modes by exclusively enabling the specified paths in the current session.

## Parameters

### `numPathArrayElements` [in]

Number of elements in *pathArray*.

### `pathArray` [in, optional]

Array of all display paths that are to be set. Only the paths within this array that have the DISPLAYCONFIG_PATH_ACTIVE flag set in the **flags** member of [DISPLAYCONFIG_PATH_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_path_info) are set. This parameter can be **NULL**. The order in which active paths appear in this array determines the path priority. For more information about path priority order, see [Path Priority Order](https://learn.microsoft.com/windows-hardware/drivers/display/path-priority-order).

### `numModeInfoArrayElements` [in]

Number of elements in *modeInfoArray*.

### `modeInfoArray` [in, optional]

Array of display source and target mode information ([DISPLAYCONFIG_MODE_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_mode_info)) that is referenced by the **modeInfoIdx** member of DISPLAYCONFIG_PATH_SOURCE_INFO and DISPLAYCONFIG_PATH_TARGET_INFO element of path information from *pathArray*. This parameter can be **NULL**.

### `flags` [in]

A bitwise OR of flag values that indicates the behavior of this function. This parameter can be one the following values, or a combination of the following values; 0 is not valid. See below for a description of valid flag combinations.

| Value | Meaning |
| --- | --- |
| **SDC_APPLY**<br><br>0x00000080 | The resulting topology, source, and target mode is set. |
| **SDC_NO_OPTIMIZATION**<br><br>0x00000100 | A modifier to the SDC_APPLY flag. This causes the change mode to be forced all the way down to the driver for each active display. |
| **SDC_USE_SUPPLIED_DISPLAY_CONFIG**<br><br>0x00000020 | The topology, source, and target mode information that are supplied in the *pathArray* and the *modeInfoArray* parameters are used, rather than looking up the configuration in the database. |
| **SDC_SAVE_TO_DATABASE**<br><br>0x00000200 | The resulting topology, source, and target mode are saved to the database. |
| **SDC_VALIDATE**<br><br>0x00000040 | The system tests for the requested topology, source, and target mode information to determine whether it can be set. |
| **SDC_ALLOW_CHANGES**<br><br>0x00000400 | If required, the function can modify the specified source and target mode information in order to create a functional display path set. |
| **SDC_TOPOLOGY_CLONE**<br><br>0x00000002 | The caller requests the last clone configuration from the persistence database. |
| **SDC_TOPOLOGY_EXTEND**<br><br>0x00000004 | The caller requests the last extended configuration from the persistence database. |
| **SDC_TOPOLOGY_INTERNAL**<br><br>0x00000001 | The caller requests the last internal configuration from the persistence database. |
| **SDC_TOPOLOGY_EXTERNAL**<br><br>0x00000008 | The caller requests the last external configuration from the persistence database. |
| **SDC_TOPOLOGY_SUPPLIED**<br><br>0x00000010 | The caller provides the path data so the function only queries the persistence database to find and use the source and target mode. |
| **SDC_USE_DATABASE_CURRENT**<br><br>(SDC_TOPOLOGY_INTERNAL \| SDC_TOPOLOGY_CLONE \| SDC_TOPOLOGY_EXTEND \| SDC_TOPOLOGY_EXTERNAL) | The caller requests a combination of all four SDC_TOPOLOGY_XXX configurations. This value informs the API to set the last known display configuration for the current connected monitors. |
| **SDC_PATH_PERSIST_IF_REQUIRED**<br><br>0x00000800 | When the function processes a SDC_TOPOLOGY_XXX request, it can force path persistence on a target to satisfy the request if necessary. For information about the other flags that this flag can be combined with, see the following list. |
| **SDC_FORCE_MODE_ENUMERATION**<br><br>0x00001000 | The caller requests that the driver is given an opportunity to update the GDI mode list while **SetDisplayConfig** sets the new display configuration. This flag value is only valid when the SDC_USE_SUPPLIED_DISPLAY_CONFIG and SDC_APPLY flag values are also specified. |
| **SDC_ALLOW_PATH_ORDER_CHANGES**<br><br>0x00002000 | A modifier to the SDC_TOPOLOGY_SUPPLIED flag that indicates that **SetDisplayConfig** should ignore the path order of the supplied topology when searching the database. When this flag is set, the topology set is the most recent topology that contains all the paths regardless of the path order. |
| **SDC_VIRTUAL_MODE_AWARE**<br><br>0x00008000 | A modifier to the SDC_USE_SUPPLIED_DISPLAY_CONFIG and SDC_TOPOLOGY_SUPPLIED flags that the caller is aware of virtual modes. Supported starting in Windows 10. |
| **SDC_VIRTUAL_REFRESH_RATE_AWARE**<br><br>0x00020000 | A modifier to the SDC_USE_SUPPLIED_DISPLAY_CONFIG and SDC_TOPOLOGY_SUPPLIED flags that the caller is aware of virtual refresh rates. Supported starting in Windows 11. |

The following list contains valid combinations of values for the *Flags* parameter:

* Either SDC_APPLY or SDC_VALIDATE must be set, but not both.
* Either SDC_USE_SUPPLIED_DISPLAY_CONFIG or any combinations of SDC_TOPOLOGY_XXX must be set. SDC_USE_SUPPLIED_DISPLAY_CONFIG cannot be set with any SDC_TOPOLOGY_XXX flag.
* SDC_NO_OPTIMIZATION can only be set with SDC_APPLY.
* SDC_ALLOW_CHANGES is allowed with any other valid combination.
* SDC_SAVE_TO_DATABASE can only be set with SDC_USE_SUPPLIED_DISPLAY_CONFIG.
* SDC_PATH_PERSIST_IF_REQUIRED cannot be used with SDC_USE_SUPPLIED_DISPLAY_CONFIG or SDC_TOPOLOGY_SUPPLIED.
* SDC_FORCE_MODE_ENUMERATION is only valid when SDC_APPLY and SDC_USE_SUPPLIED_DISPLAY_CONFIG are specified.
* SDC_ALLOW_PATH_ORDER_CHANGES is allowed only when SDC_TOPOLOGY_SUPPLIED is specified.
* SDC_TOPOLOGY_SUPPLIED cannot be used with any other SDC_TOPOLOGY_XXX flag. Because of a validation issue, if a caller violates this rule, **SetDisplayConfig** does not fail. However, **SetDisplayConfig** ignores the SDC_TOPOLOGY_SUPPLIED flag.

SDC_TOPOLOGY_XXX flags can be used in combinations. For example, if SDC_TOPOLOGY_CLONE and SDC_TOPOLOGY_EXTEND are set, the API uses the most recent clone or extend topology, which every topology was set with most recently for the current connected monitors.

## Return value

The function returns one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function succeeded. |
| **ERROR_INVALID_PARAMETER** | The combination of parameters and flags specified is invalid. |
| **ERROR_NOT_SUPPORTED** | The system is not running a graphics driver that was written according to the [Windows Display Driver Model (WDDM)](https://learn.microsoft.com/windows-hardware/drivers/display/windows-vista-display-driver-model-design-guide). The function is only supported on a system with a WDDM driver running. |
| **ERROR_ACCESS_DENIED** | The caller does not have access to the console session. This error occurs if the calling process does not have access to the current desktop or is running on a remote session. |
| **ERROR_GEN_FAILURE** | An unspecified error occurred. |
| **ERROR_BAD_CONFIGURATION** | The function could not find a workable solution for the source and target modes that the caller did not specify. |

## Remarks

The **SetDisplayConfig** function takes the active display paths with any specified source and target mode information and uses best mode logic to generate any missing source and target mode information. This function then sets the complete display path.

The **ModeInfoIdx** members in the [DISPLAYCONFIG_PATH_SOURCE_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_path_source_info) and [DISPLAYCONFIG_PATH_TARGET_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_path_target_info) structures are used to indicate whether source and target mode are supplied for a given active path. If the index value is DISPLAYCONFIG_PATH_MODE_IDX_INVALID for either, this indicates the mode information is not being specified. It is valid for the path plus source mode or the path plus source and target mode information to be specified for a given path. However, it is not valid for the path plus target mode to be specified without the source mode.

The source and target modes for each source and target identifiers can only appear in the *modeInfoArray* array once. For example, a source mode for source identifier S1 can only appear in the table once; if multiple paths reference the same source, they have to use the same **ModeInfoIdx**.

The expectation is that most callers use [QueryDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-querydisplayconfig) to get the current configuration along with other valid possibilities and then use **SetDisplayConfig** to test and set the configuration.

The order in which the active paths appear in the *PathArray* array determines the path priority.

By default, **SetDisplayConfig** never changes any supplied path, source mode, or target mode information. If best mode logic cannot find a solution without changing the specified display path information, **SetDisplayConfig** fails with ERROR_BAD_CONFIGURATION. In this case, the caller should specify the SDC_ALLOW_CHANGES flag to allow the function to tweak some of the specified source and mode details to allow the display path change to be successful.

If the specified or calculated source and target modes have the same dimensions, **SetDisplayConfig** automatically sets the path scaling to DISPLAYCONFIG_PPR_IDENTITY before setting the display path and saving it in the database. For information about how **SetDisplayConfig** handles scaling, see [Scaling the Desktop Image](https://learn.microsoft.com/windows-hardware/drivers/display/scaling-the-desktop-image).

When the caller specifies the SDC_USE_SUPPLIED_DISPLAY_CONFIG flag to set a clone path and if any source mode indexes are invalid in the path array, **SetDisplayConfig** determines that all of the source mode indexes from that source are invalid. **SetDisplayConfig** uses the best mode logic to determine the source mode information.

Except for the SDC_TOPOLOGY_SUPPLIED flag (for more information about SDC_TOPOLOGY_SUPPLIED, see the following paragraph), the SDC_TOPOLOGY_XXX flags set last display path settings, including the source and target mode information for that topology type. For information about valid SDC_TOPOLOGY_XXX flag combinations, see the *Flags* parameter description. The *pathArray* and *modeInfoArray* parameters must be **NULL**, and their associated sizes must be zero. For example, if SDC_TOPOLOGY_CLONE and SDC_TOPOLOGY_EXTEND are set, this function uses the most recent clone or extend display path configuration. If a single topology type is requested, the last configuration of that type is used. If that topology had never been set before, **SetDisplayConfig** uses the best topology logic to find the best topology, and then best mode logic to find the best source and target mode to use. If a combination of the topology flags had been set and none of them had database entries, the following priority is used. For laptops: clone, extend, internal, and then external; for desktops the priority is extend and then clone.

The caller can specify the SDC_TOPOLOGY_SUPPLIED flag to indicate that it sets just the path information (topology) and requests that **SetDisplayConfig** obtains and then uses the source and target mode information from the persistence database. If the active paths that the caller supplies do not have an entry in the persistence database, **SetDisplayConfig** fails. In this case, if the caller calls **SetDisplayConfig** again with the same path data but with the SDC_USE_SUPPLIED_DISPLAY_CONFIG flag set, **SetDisplayConfig** uses best mode logic to create the source and target mode information. When the caller specifies SDC_TOPOLOGY_SUPPLIED, the caller must set the *numModeInfoArrayElements* parameter to zero and the *modeInfoArray* parameter to **NULL**; however, the caller must set the *pathArray* and *numPathArrayElements* parameters for the path information that the caller requires. The caller must mark all the source and target mode indexes as invalid (DISPLAYCONFIG_PATH_MODE_IDX_INVALID) in this path data.

The following table provides some common scenarios where **SetDisplayConfig** is called along with the flag combinations that the caller passes to the *Flags* parameter to achieve the scenarios.

| Scenario | Flag combination |
| --- | --- |
| Test whether a specified display configuration is supported on the computer | SDC_VALIDATE \| SDC_USE_SUPPLIED_DISPLAY_CONFIG |
| Set a specified display configuration and save to the database | SDC_APPLY \| SDC_USE_SUPPLIED_DISPLAY_CONFIG \| SDC_SAVE_TO_DATABASE |
| Set a temporary display configuration (that is, the display configuration will not be saved) | SDC_APPLY \| SDC_USE_SUPPLIED_DISPLAY_CONFIG |
| Test whether clone is supported on the computer | SDC_VALIDATE \| SDC_TOPOLOGY_CLONE |
| Set clone topology | SDC_APPLY \| SDC_TOPOLOGY_CLONE |
| Set clone topology and allow path persistence to be enabled if required to satisfy the request | SDC_APPLY \| SDC_TOPOLOGY_CLONE \| SDC_PATH_PERSIST_IF_REQUIRED |
| Return from a temporary mode to the last saved display configuration | SDC_APPLY\| SDC_USE_DATABASE_CURRENT |
| Given only the path information, set the display configuration with the source and target information from the database for the paths and ignore the path order | SDC_APPLY \| SDC_TOPOLOGY_SUPPLIED \| SDC_ALLOW_PATH_ORDER_CHANGES |

### DPI Virtualization

This API does not participate in DPI virtualization. All sizes in the DEVMODE structure are in terms of physical pixels, and are not related to the calling context.

## See also

[DISPLAYCONFIG_MODE_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_mode_info)

[DISPLAYCONFIG_PATH_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_path_info)

[DISPLAYCONFIG_PATH_SOURCE_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_path_source_info)

[DISPLAYCONFIG_PATH_TARGET_INFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_path_target_info)

[QueryDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-querydisplayconfig)