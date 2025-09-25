## Description

The **AcxPnpEventGenerateEvent** function generates an ACX PNP event.

## Parameters

### `Event`

The ACXPNPEVENT object (described in [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects)).

### `Payload`

The event payload.

### `Size`

The size of the event payload.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

The Payload is specific to the type of PNP event generated.

An ACXPNPEVENT represents an asynchronous notification available at the driver level. PNP events can be added to any objects. Currently they are used with ACXAUDIOMODULE and ACXKEYWARDSPOTTER objects. Internally ACXPNPEVENTs are exposed as PNP asynchronous notification to upper layers.

### Example

This example code snip, shows the use of AcxPnpEventGenerateEvent.

```cpp
        AUDIOMODULE_CUSTOM_NOTIFICATION customNotification = {0};

        customNotification.Type = AudioModuleParameterChanged;
        customNotification.ParameterChanged.ParameterId = command->ParameterId;

        status = AcxPnpEventGenerateEvent(audioModuleCtx->Event, &customNotification, (USHORT)sizeof(customNotification));
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxevents.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxevents/)