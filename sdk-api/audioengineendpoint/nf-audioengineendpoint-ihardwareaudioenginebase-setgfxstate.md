# IHardwareAudioEngineBase::SetGfxState

## Description

The **SetGfxState** method sets the GFX state of the offloaded audio stream.

## Parameters

### `pDevice` [in]

Pointer to an [IMMDevice](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immdevice) interface.

### `_bEnable` [in]

Pointer to a boolean variable.

## Return value

The **SetGfxState** method returns S_OK to indicate that it has completed successfully. Otherwise it returns an appropriate error code.

## See also

[IHardwareAudioEngineBase](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-ihardwareaudioenginebase)

[IMMDevice](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immdevice)