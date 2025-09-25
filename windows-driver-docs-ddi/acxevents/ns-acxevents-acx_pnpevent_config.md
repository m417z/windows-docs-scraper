## Description

The **ACX_PNPEVENT_CONFIG** structure is used to configure an ACXPNPEVENT.

## Members

### `Size`

The length, in bytes, of this structure.

### `Flags`

Bitwise OR of [ACX_PNPEVENT_CONFIG_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxevents/ne-acxevents-acx_pnpevent_config_flags).

### `Event`

A GUID that is used to identify the event.

## Remarks

The Event GUID is automatically retrieved from the ACXAUDIOMODULE and ACXKEYWORDSPOTTER when the event is associated with these two types of objects.

### Example

This example shows the use of the ACX_PNPEVENT_CONFIG structure.

```cpp
    ACX_PNPEVENT_CONFIG audioModuleEventCfg;
...

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