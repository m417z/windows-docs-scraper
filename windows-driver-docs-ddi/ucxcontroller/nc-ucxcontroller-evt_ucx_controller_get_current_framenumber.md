# EVT_UCX_CONTROLLER_GET_CURRENT_FRAMENUMBER callback function

## Description

The client driver's implementation that UCX calls to retrieve the current 32-bit frame number.

## Parameters

### `UcxController` [in]

 A handle to the UCX controller that the client driver received in a previous call to the [UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85)) method.

### `FrameNumber` [out]

A pointer to the current 32-bit frame number.

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it must return a status value for which NT_SUCCESS(status) equals FALSE.

## Remarks

The UCX client driver registers its *EVT_UCX_CONTROLLER_GET_CURRENT_FRAMENUMBER* implementation with the USB host controller extension (UCX) by calling the [UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85)) method.

#### Examples

```
NTSTATUS
Controller_EvtControllerGetCurrentFrameNumber(
    UCXCONTROLLER   UcxController,
    PULONG          FrameNumber
)

{
    UNREFERENCED_PARAMETER(UcxController);

    //
    // TODO: Return the current 32-bit frame number.  Do not access the
    // controller registers if the controller is not in D0.
    //

    *FrameNumber = 0xFFFFFFFF;

    DbgTrace(TL_INFO, Controller, "Controller_EvtControllerGetCurrentFrameNumber");

    return STATUS_SUCCESS;
}
```

## See also

[UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85))