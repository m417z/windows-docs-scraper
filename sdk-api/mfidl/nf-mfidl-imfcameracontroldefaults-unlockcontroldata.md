## Description

Unlocks the control data buffer unlocked with a call to [LockControlData](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameracontroldefaults-lockcontroldata).

## Return value

S_OK on success.

## Remarks

After calling **UnlockCOntrolData**, clients should not modify the contents of the control data buffer. Doing so will result in undefined behavior.

## See also

[LockControlData](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameracontroldefaults-lockcontroldata)