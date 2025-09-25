# ISpatialAudioObjectBase::GetAudioObjectType

## Description

Gets a value specifying the type of audio object that is represented by the [ISpatialAudioObject](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobject). This value indicates if the object is dynamic or static. If the object is static, one and only one of the static audio channel values to which the object is assigned is returned.

## Parameters

### `audioObjectType` [out]

A value specifying the type of audio object that is represented

## Return value

If the method succeeds, it returns S_OK.

## Remarks

Set the type of the audio object with the *type* parameter to the [ISpatialAudioObjectRenderStream::ActivateSpatialAudioObject](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectrenderstream-activatespatialaudioobject) method.

## See also

[ISpatialAudioObject](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobject)

[ISpatialAudioObjectBase](https://learn.microsoft.com/windows/win32/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobjectbase)