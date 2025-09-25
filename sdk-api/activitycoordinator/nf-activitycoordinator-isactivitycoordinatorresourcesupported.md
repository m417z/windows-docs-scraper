## Description

This function allows apps to check for supported resources at runtime. Some resource types, such as Neural Processing Unit (NPU) resources, may not be supported on all systems.

## Parameters

### `Resource`

The [ACTIVITY_COORDINATOR_RESOURCE](https://learn.microsoft.com/windows/win32/api/activitycoordinatortypes/ne-activitycoordinatortypes-activity_coordinator_resource) type to check for support.

## Return value

Returns a `BOOL` value indicating whether the resource is supported on the current system.

## -examples

See [Checking for Activity Coordinator NPU support](https://learn.microsoft.com/windows/win32/activity_coordinator/checking-for-npu-support-example) for an example of how to use this function to check for supported resource types at runtime.

## Remarks

The version of Activity Coordinator that an application compiles with may be different than what is on the system at runtime. Applications will need to check for resource availability using the provided API and adapt their program as necessary. This enables applications to differentiate between a lack of feature support and passing invalid parameters to an API.

Developers should keep in mind that Activity Coordinator resource support does not indicate if such resources are present on the system. Devices like GPUs and NPUs can be added and removed at runtime, and developers should refer to the library or framework they are using for how to best handle such situations. As Activity Coordinator does not control how or when work runs, developers must take care to create policies that reflect how their application consumes resources. If, for example, work is run on the Graphics Processing Unit (GPU) when no NPUs are present, developers should create policies that monitor both or switch between an NPU or GPU based policy as needed.

## See also

- [ACTIVITY_COORDINATOR_RESOURCE](https://learn.microsoft.com/windows/win32/api/activitycoordinatortypes/ne-activitycoordinatortypes-activity_coordinator_resource)
- [Checking for Activity Coordinator resource support](https://learn.microsoft.com/windows/win32/activity_coordinator/checking-for-resource-support-example)