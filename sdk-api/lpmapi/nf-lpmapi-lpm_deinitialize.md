# LPM_Deinitialize function

## Description

The
*LPM_Deinitialize* function allows the PCM to instruct LPMs to deinitialize, whether due to system shutdown or a change in Designated Subnet Bandwidth Manager (DSBM) status. This occurs when the Admission Control Service no longer needs to do policy based–admission control, such as when a demotion from DSBM status occurs. LPMs should free resources, close connections to external entities such as policy server or directory services, and perform any other cleanup necessary to properly relinquish LPM activities. The PCM will unload the DLL after
*LPM_Deinitialize* returns.

## Parameters

### `LpmHandle`

Unique handle to the LPM, as supplied through
[LPM_Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nf-lpmapi-lpm_initialize) during initialization.

## Return value

If another value is returned from
*LPM_Deinitialize*, the PCM will record the name of this DLL (implementations of LPMs are always in the form of a DLL), as well as this return value, in the Event Log.

## Remarks

LPMs do not need to return errors for outstanding requests when
*LPM_Deinitialize* is called; PCM assumes LPV_REJECT for outstanding requests. LPMs should deinitialize synchronously before returning. If an LPM has been loaded and initialized multiple times to facilitate the handling of multiple PE types, the PCM will call
*LPM_Deinitialize* multiple times as well.

## See also

[LPM_Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/nf-lpmapi-lpm_initialize)