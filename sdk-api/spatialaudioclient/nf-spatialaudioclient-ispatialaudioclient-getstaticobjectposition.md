# ISpatialAudioClient::GetStaticObjectPosition

## Description

Gets the position in 3D space of the specified static spatial audio channel.

## Parameters

### `type` [in]

A value indicating the static spatial audio channel for which the position is being queried. This method will return E_INVALIDARG if the value does not represent a static channel, including **AudioObjectType_Dynamic** and **AudioObjectType_None**.

### `x` [out]

The x coordinate of the static audio channel, in meters, relative to the listener. Positive values are to the right of the listener and negative values are to the left.

### `y` [out]

The y coordinate of the static audio channel, in meters, relative to the listener. Positive values are above the listener and negative values are below.

### `z` [out]

The z coordinate of the static audio channel, in meters, relative to the listener. Positive values are behind the listener and negative values are in front.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The supplied [AudioObjectType](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/ne-spatialaudioclient-audioobjecttype) value does not represent a static channel. |

## Remarks

 Position values use a right-handed Cartesian coordinate system, where each unit represents 1 meter. The coordinate system is relative to the listener where the origin (x=0.0, y=0.0, z=0.0) represents the center point between the listener's ears.

## See also

[ISpatialAudioClient](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioclient)