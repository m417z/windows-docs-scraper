# EVT_UCX_CONTROLLER_RESET callback function

## Description

The client driver's implementation that UCX calls to reset the controller.

## Parameters

### `UcxController` [in]

 A handle to the UCX controller that the client driver received in a previous call to the [UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85)) method.

## Remarks

The UCX client driver registers its *EVT_UCX_CONTROLLER_RESET* implementation with the USB host controller extension (UCX) by calling the [UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85)) method.

The client driver indicates completion of this event by calling the [UcxControllerResetComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nf-ucxcontroller-ucxcontrollerresetcomplete) method. Doing so ensures that UCX does not call *EVT_UCX_CONTROLLER_RESET* a second time before this event callback completes.

If the client driver calls [UcxControllerNeedsReset](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nf-ucxcontroller-ucxcontrollerneedsreset), UCX calls this event callback function. However, UCX may call this event callback function even when the client driver has not called **UcxControllerNeedsReset**.

#### Examples

```
VOID
Controller_EvtControllerReset(
    UCXCONTROLLER UcxController
)

{
    UCX_CONTROLLER_RESET_COMPLETE_INFO controllerResetCompleteInfo;

    //
    // TODO: Reset the controller
    //

    //
    // TODO: Were devices and endpoints programmed in the controller before the reset
    // still programmed in the controller after the reset?
    //
    UCX_CONTROLLER_RESET_COMPLETE_INFO_INIT(&controllerResetCompleteInfo,
                                            UcxControllerStateLost,
                                            TRUE); // reset due to UCX, received EvtReset after WDF power-up

    DbgTrace(TL_INFO, Controller, "Controller_EvtControllerReset");

    UcxControllerResetComplete(UcxController, &controllerResetCompleteInfo);
}
```

## See also

[UcxControllerCreate](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt188033(v=vs.85))

[UcxControllerNeedsReset](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nf-ucxcontroller-ucxcontrollerneedsreset)

[UcxControllerResetComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nf-ucxcontroller-ucxcontrollerresetcomplete)