## Description

The **IDirectInputEffectDriver::GetVersions**  method obtains version information about the force-feedback hardware and driver.

## Parameters

### `unnamedParam1`

Points to a [DIDRIVERVERSIONS](https://learn.microsoft.com/windows/desktop/api/dinputd/ns-dinputd-didriverversions) structure that should be filled in with version information describing the hardware, firmware, and driver. DirectInput sets the **dwSize** member of the DIDRIVERVERSIONS structure to **sizeof**(DIDRIVERVERSIONS) before calling this method.

## Return value

Returns S_OK if successful; otherwise, returns an error code.