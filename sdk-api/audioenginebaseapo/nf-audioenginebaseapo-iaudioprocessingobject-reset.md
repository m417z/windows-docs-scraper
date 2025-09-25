## Description

The Reset method resets the APO to its original state. This method does not cause any changes in the connection objects that are attached to the input or the output of the APO.

## Return value

The `Reset` method returns a value of S_OK when the call is completed successfully.

## Remarks

This method is not real-time compliant and must not be called from a real-time processing thread. The implementation of this method does not and must not touch paged memory. Additionally, it must not call any blocking system routines.

## See also

[IAudioProcessingObject](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/nn-audioenginebaseapo-iaudioprocessingobject)