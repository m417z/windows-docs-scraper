# PSTARTUP_EX_ROUTINE callback function

## Description

Loads a [resource DLL](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dlls), returning a structure
that contains a function table and a version number. The **PSTARTUP_EX_ROUTINE**
type defines a pointer to this function.

## Parameters

### `ResourceType` [in]

The type of resource to start.

### `MinVersionSupported` [in]

The minimum version of the [Resource API](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-api) supported by the
[Cluster service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-service).

### `MaxVersionSupported` [in]

The maximum version of the Resource API supported by the Cluster service.

### `MonitorCallbackFunctions` [in] [in]

TBD

### `ResourceDllInterfaceFunctions` [out] [out]

TBD

## Return value

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The request was successful. |
| **ERROR_REVISION_MISMATCH**<br><br>1306 (0x51A) | The resource DLL does not support a version that falls in the range identified by the *MinVersionSupported* and *MaxVersionSupported* parameters. |

## See also

[Resource DLL Entry-Point Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-entry-point-functions)