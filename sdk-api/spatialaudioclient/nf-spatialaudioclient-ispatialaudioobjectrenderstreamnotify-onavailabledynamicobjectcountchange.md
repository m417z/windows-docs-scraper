# ISpatialAudioObjectRenderStreamNotify::OnAvailableDynamicObjectCountChange

## Description

Notifies the spatial audio client when the rendering capacity for an [ISpatialAudioObjectRenderStream](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobjectrenderstream) is about to change, specifies the time after which the change will occur, and specifies the number of dynamic audio objects that will be available after the change.

## Parameters

### `sender` [in]

The spatial audio render stream for which the available dynamic object count is changing.

### `hnsComplianceDeadlineTime` [in]

The time after which the spatial resource limit will change, in 100-nanosecond units. A value of 0 means that the change will occur immediately.

### `availableDynamicObjectCountChange` [in]

The number of dynamic spatial audio objects that will be available to the stream after *hnsComplianceDeadlineTime*.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

A dynamic [ISpatialAudioObject](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobject) is one that was activated by setting the *type* parameter to the [ISpatialAudioObjectRenderStream::ActivateSpatialAudioObject](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectrenderstream-activatespatialaudioobject) method to **AudioObjectType_Dynamic**. The client has a limit of the maximum number of dynamic spatial audio objects that can be activated at one time. When the capacity of the audio rendering pipeline changes, the system will dynamically adjust the maximum number of concurrent dynamic spatial audio objects. Before doing so, the system will call **OnAvailableDynamicObjectCountChange** to notify clients of the resource limit change.

Call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on an **ISpatialAudioObject** when it is no longer being used to free up the resource to create new dynamic spatial audio objects.

## See also

[ISpatialAudioObjectRenderStreamNotify](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobjectrenderstreamnotify)