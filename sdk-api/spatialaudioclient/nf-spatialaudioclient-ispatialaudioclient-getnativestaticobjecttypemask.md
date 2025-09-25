# ISpatialAudioClient::GetNativeStaticObjectTypeMask

## Description

Gets a channel mask which represents the subset of static speaker bed channels native to current rendering engine.

## Parameters

### `mask` [out]

A bitwise combination of values from the [AudioObjectType](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/ne-spatialaudioclient-audioobjecttype) enumeration indicating a subset of static speaker channels. The values returned will only include the static channel values and will not include **AudioObjectType_Dynamic**.

## Return value

If the method succeeds, it returns S_OK.

## See also

[ISpatialAudioClient](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioclient)