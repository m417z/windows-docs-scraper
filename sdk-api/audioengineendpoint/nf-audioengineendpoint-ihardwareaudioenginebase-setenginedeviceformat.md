# IHardwareAudioEngineBase::SetEngineDeviceFormat

## Description

The **SetEngineDeviceFormat** method sets the waveform audio format for the hardware audio engine.

## Parameters

### `pDevice` [in]

A pointer to an [IMMDevice](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immdevice) interface.

### `_pwfxFormat` [in]

A pointer to a [WAVEFORMATEX](https://learn.microsoft.com/windows/win32/api/mmreg/ns-mmreg-waveformatex) structure that provides information about the hardware audio engine.

## Return value

The **SetEngineDeviceFormat** method returns **S_OK** to indicate that it has completed successfully. Otherwise it returns an appropriate error code.

## See also

[IHardwareAudioEngineBase](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-ihardwareaudioenginebase)

[IMMDevice](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immdevice)