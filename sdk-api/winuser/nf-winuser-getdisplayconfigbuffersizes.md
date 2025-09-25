# GetDisplayConfigBufferSizes function

## Description

The **GetDisplayConfigBufferSizes** function retrieves the size of the buffers that are required to call the [QueryDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-querydisplayconfig) function.

## Parameters

### `flags` [in]

The type of information to retrieve. The value for the *Flags* parameter must be one of the following values.

#### QDC_ALL_PATHS

The caller requests the table sizes to hold all the possible path combinations.

#### QDC_ONLY_ACTIVE_PATHS

The caller requests the table sizes to hold only active paths.

#### QDC_DATABASE_CURRENT

The caller requests the table sizes to hold the active paths as defined in the persistence database for the currently connected monitors.

### `numPathArrayElements` [out]

Pointer to a variable that receives the number of elements in the path information table. The *pNumPathArrayElements* parameter value is then used by a subsequent call to the [QueryDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-querydisplayconfig) function. This parameter cannot be **NULL**.

### `numModeInfoArrayElements` [out]

Pointer to a variable that receives the number of elements in the mode information table. The *pNumModeInfoArrayElements* parameter value is then used by a subsequent call to the [QueryDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-querydisplayconfig) function. This parameter cannot be **NULL**.

## Return value

The function returns one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function succeeded. |
| **ERROR_INVALID_PARAMETER** | The combination of parameters and flags that are specified is invalid. |
| **ERROR_NOT_SUPPORTED** | The system is not running a graphics driver that was written according to the [Windows Display Driver Model (WDDM)](https://learn.microsoft.com/windows-hardware/drivers/display/windows-vista-display-driver-model-design-guide). The function is only supported on a system with a WDDM driver running. |
| **ERROR_ACCESS_DENIED** | The caller does not have access to the console session. This error occurs if the calling process does not have access to the current desktop or is running on a remote session. |
| **ERROR_GEN_FAILURE** | An unspecified error occurred. |

## Remarks

Given the current display path configuration and the requested flags, **GetDisplayConfigBufferSizes** returns the size of the path and mode tables that are required to store the information. **GetDisplayConfigBufferSizes** can return values that are slightly larger than are actually required because it determines that all source and target paths are valid; whereas, the driver might place some restrictions on the possible combinations.

As **GetDisplayConfigBufferSizes** can only determine the required array size of that moment in time, it is possible that between calls to **GetDisplayConfigBufferSizes** and [QueryDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-querydisplayconfig) the system configuration has changed and the provided array sizes are no longer sufficient to store the new path data.

If a caller is aware that it must enable additional sources and targets, the caller can allocate a larger mode information array than is returned from **GetDisplayConfigBufferSizes** so that it has the space to add the additional source and target modes after calling **QueryDisplayConfig** and before calling [SetDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdisplayconfig).

## Examples

See [__QueryDisplayConfig__](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-querydisplayconfig#examples) for an example of __GetDisplayConfigBufferSizes__.

## See also

[QueryDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-querydisplayconfig)

[SetDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdisplayconfig)