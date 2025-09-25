## Description

The **ACX_PNPEVENT_CONFIG_INIT** function initializes an [ACX_PNPEVENT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxevents/ns-acxevents-acx_pnpevent_config) structure. No inputs are used with this function.

## Parameters

### `Config`

An initialized [ACX_PNPEVENT_CONFIG structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxevents/ns-acxevents-acx_pnpevent_config) that will be used to describe the configuration of the event.

## Remarks

### Example

The example shows the use of the ACX_PNPEVENT_CONFIG_INIT.

```cpp

    ACX_PNPEVENT_CONFIG audioModuleEventCfg;

    ACX_PNPEVENT_CONFIG_INIT(&audioModuleEventCfg);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxevents.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxevents/)