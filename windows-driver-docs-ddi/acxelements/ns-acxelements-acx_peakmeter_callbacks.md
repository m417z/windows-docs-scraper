## Description

The **ACX_PEAKMETER_CALLBACKS** structure identifies the driver callbacks for ACX peakmeter operations.

## Members

### `Size`

The length, in bytes, of this structure.

### `EvtAcxPeakMeterRetrieveLevel`

The [ACX_PEAKMETER_RETRIEVE_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/nc-acxelements-evt_acx_peakmeter_retrieve_level) callback.

### `EvtAcxPeakMeterProcessRequest`

The [EVT_ACX_OBJECT_PROCESS_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/nc-acxrequest-evt_acx_object_process_request) callback.

## Remarks

### Example

Example usage is shown below.

```cpp
    ACX_PEAKMETER_CALLBACKS         peakmeterCallbacks;
    ACX_PEAKMETER_CONFIG            peakmeterCfg;
    ACXPEAKMETER                    peakmeterElement;

...
        ACX_PEAKMETER_CALLBACKS peakmeterCallbacks;
        ACX_PEAKMETER_CALLBACKS_INIT(&peakmeterCallbacks);
        peakmeterCallbacks.EvtAcxPeakMeterRetrieveLevel = CodecR_EvtPeakMeterRetrieveLevelCallback;

        ACX_PEAKMETER_CONFIG peakmeterCfg;
        ACX_PEAKMETER_CONFIG_INIT(&peakmeterCfg);
        peakmeterCfg.ChannelsCount = MAX_CHANNELS;
        peakmeterCfg.Minimum = PEAKMETER_MINIMUM;
        peakmeterCfg.Maximum = PEAKMETER_MAXIMUM;
        peakmeterCfg.SteppingDelta = PEAKMETER_STEPPING_DELTA;
        peakmeterCfg.Callbacks = &peakmeterCallbacks;
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)