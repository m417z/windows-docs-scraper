## Description

The **AcxPnpEventCreate** function creates an ACXPNPEVENT.

## Parameters

### `Device`

An existing WDFDEVICE object (described in [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects)) that be associated with the new event.

### `Object`

An existing ACXAUDIOMODULE object that is described in [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects) that will be associated with the event.

### `Attributes`

Additional Attributes defined using a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) that are used to set the various object's values: cleanup and destroy callbacks, context type, and to specify its parent object.

### `Config`

An [ACX_PNPEVENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxevents/ns-acxevents-acx_pnpevent_config) structure that defines the configuration for an ACX PNP event.

### `Event`

The ACXEVENT object (described in [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects)).

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

An ACXPNPEVENT represents an asynchronous notification available at the driver level. PNP events can be added to any objects. Currently they are used with ACXAUDIOMODULE and ACXKEYWARDSPOTTER objects. Internally AcxPnpEvents are exposed as PNP asynchronous notification to upper layers.

### Example

This example code shows the use of AcxPnpEventCreate.

```cpp
    NTSTATUS                        status;
    ACXAUDIOMODULE                  audioModuleElement;
    WDF_OBJECT_ATTRIBUTES           attributes;
    ACX_PNPEVENT_CONFIG             audioModuleEventCfg;
    ACXPNPEVENT                     audioModuleEvent;

    ...

    status = AcxAudioModuleCreate(Circuit, &attributes, &audioModuleCfg, &audioModuleElement);
    audioModule0Ctx = GetCodecAudioModule0Context(audioModuleElement);

    ACX_PNPEVENT_CONFIG_INIT(&audioModuleEventCfg);
    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&attributes, CODEC_PNPEVENT_CONTEXT);
    attributes.ParentObject = audioModuleElement;
    status = AcxPnpEventCreate(Device, audioModuleElement, &attributes, &audioModuleEventCfg, &audioModuleEvent);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxevents.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxevents/)