# IHardwareAudioEngineBase::GetEngineFormat

## Description

The **GetEngineFormat** method retrieves the current data format of the offloaded audio stream.

## Parameters

### `pDevice` [in]

A pointer to an [IMMDevice](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immdevice) interface.

### `_bRequestDeviceFormat` [in]

A Boolean variable that indicates whether or not the **IMMDevice** interface is being accessed to retrieve the device format.

### `_ppwfxFormat` [out]

A pointer to a pointer to a [WAVEFORMATEX](https://learn.microsoft.com/windows/win32/api/mmreg/ns-mmreg-waveformatex) structure that provides information about the hardware audio engine. This includes the waveform audio format type, the number of audio channels, and the sample rate of the audio engine.

## Return value

The **GetEngineFormat** method returns **S_OK** to indicate that it has completed successfully. Otherwise it returns an appropriate error code.

## See also

[IHardwareAudioEngineBase](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-ihardwareaudioenginebase)

[IMMDevice](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immdevice)

[WAVEFORMATEX](https://learn.microsoft.com/windows/win32/api/mmreg/ns-mmreg-waveformatex)