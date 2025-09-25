# ISpatialAudioClient::GetMaxDynamicObjectCount

## Description

Gets the maximum number of dynamic audio objects for the spatial audio client.

## Parameters

### `value` [out]

Gets the maximum dynamic object count for this client.

## Return value

If the method succeeds, it returns S_OK.

## Remarks

A dynamic [ISpatialAudioObject](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobject) is one that was activated by setting the *type* parameter to the [ISpatialAudioObjectRenderStream::ActivateSpatialAudioObject](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectrenderstream-activatespatialaudioobject) method to **AudioObjectType_Dynamic**. The client has a limit of the maximum number of dynamic spatial audio objects that can be activated at one time. When the capacity of the audio rendering pipeline changes, the system will dynamically adjust the maximum number of concurrent dynamic spatial audio objects. Before doing so, the system will call [OnAvailableDynamicObjectCountChange](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectrenderstreamnotify-onavailabledynamicobjectcountchange) to notify clients of the resource limit change.

Call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on an **ISpatialAudioObject** when it is no longer being used to free up the resource to create new dynamic spatial audio objects.

When Windows Sonic is not available (for instance, when playing to embedded laptop stereo speakers, or if the user has not explicitly enabled Windows Sonic on the device), the number of available dynamic objects returned by **GetMaxDynamicObjectCount** to an application will be 0.

## See also

[ISpatialAudioClient](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioclient)