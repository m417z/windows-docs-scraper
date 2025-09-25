# MFCreateSensorProfile function

## Description

Creates a sensor profile, based on the specified type, index, and optional constraints.

## Parameters

### `ProfileType` [in]

The profile type to create.

### `ProfileIndex` [in, out]

The profile index.

### `Constraints` [in, optional]

Any optional constraints to be put on the profile.

### `ppProfile` [out]

On success, returns a double pointer to the [IMFSensorProfile](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorprofile) containing the sensor profile.

## Return value

This function does not return a value.