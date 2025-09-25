# IAudioProcessingObject::GetRegistrationProperties

## Description

GetRegistrationProperties returns the registration properties of the audio processing object (APO).

## Parameters

### `ppRegProps` [out]

The registration properties of the APO. This parameter is of type [APO_REG_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/ns-audioenginebaseapo-apo_reg_properties).

## Return value

`GetRegistrationProperties` returns a

value of S_OK if the call was successful. Otherwise, it returns an error code of E_POINTER to indicate that an invalid pointer was passed to the function.

## Remarks

The caller must free the memory returned by `GetRegistrationProperties`.

**Note**

This method must not be called from a real-time processing thread.

## See also

[IAudioProcessingObject](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/nn-audioenginebaseapo-iaudioprocessingobject)