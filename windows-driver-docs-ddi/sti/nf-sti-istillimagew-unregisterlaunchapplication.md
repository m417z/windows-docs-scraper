# IStillImageW::UnregisterLaunchApplication

## Description

The **IStillImage::UnregisterLaunchApplication** method removes an application from the still image event monitor's list of push-model aware applications.

## Parameters

### `pwszAppName` [in]

Caller-supplied pointer to the application's "short name".

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

The **IStillImage::UnRegisterLaunchApplication** method should be called as part of the process of uninstalling a push-model aware application. The method can be uninstalled either by the application itself or by other uninstalling software.

Before calling **IStillImage::UnRegisterLaunchApplication**, clients of the **IStillImage** COM interface must call [IStillImage::StiCreateInstance](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543804(v=vs.85)) to obtain an **IStillImage** interface pointer.

## See also

[IStillImage::RegisterLaunchApplication](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543798(v=vs.85))

[IStillImageW](https://learn.microsoft.com/windows-hardware/drivers/ddi/_image/)