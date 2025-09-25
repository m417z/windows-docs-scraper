# TSPI_phoneGetStatus function

## Description

The
**TSPI_phoneGetStatus** function queries the specified open phone device for its overall status.

## Parameters

### `hdPhone`

The handle to the phone to be queried.

### `lpPhoneStatus`

A pointer to a variably sized data structure of type
[PHONESTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonestatus), into which the service provider writes information about the phone's status. Prior to calling
**TSPI_phoneGetStatus**, the application sets the **dwTotalSize** member of this structure to indicate the amount of memory available to TAPI for returning information.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

PHONEERR_INVALPHONEHANDLE, PHONEERR_OPERATIONFAILED, PHONEERR_NOMEM, PHONEERR_OPERATIONUNAVAIL, PHONEERR_RESOURCEUNAVAIL.

## Remarks

The following table indicates which members of the
[PHONESTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonestatus) data structure are filled in by TAPI and which members are filled in by the service provider. The service provider must not overwrite the values filled in by TAPI.

| Member | TAPI | Service provider |
| --- | --- | --- |
| **dwTotalSize;** | X |  |
| **dwNeededSize;** |  | X |
| **dwUsedSize;** |  | X |
| **dwStatusFlags;** |  | X |
| **dwNumOwners;** | X |  |
| **dwNumMonitors;** | X |  |
| **dwRingMode;** |  | X |
| **dwRingVolume;** |  | X |
| **dwHandsetHookSwitchMode;** |  | X |
| **dwHandsetVolume;** |  | X |
| **dwHandsetGain;** |  | X |
| **dwSpeakerHookSwitchMode;** |  | X |
| **dwSpeakerVolume;** |  | X |
| **dwSpeakerGain;** |  | X |
| **dwHeadsetHookSwitchMode;** |  | X |
| **dwHeadsetVolume;** |  | X |
| **dwHeadsetGain;** |  | X |
| **dwDisplaySize;** |  | X |
| **dwDisplayOffset;** |  | X |
| **dwLampModesSize;** |  | X |
| **dwLampModesOffset;** |  | X |
| **dwOwnerNameSize;** | X |  |
| **dwOwnerNameOffset;** | X |  |
| **dwDevSpecificSize;** |  | X |
| **dwDevSpecificOffset;** |  | X |

TAPI can use this function to determine the current state of an open phone device. The status information describes information about the phone device's hookswitch devices, ringer, volume, display, and lamps of the open phone.

## See also

[PHONESTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonestatus)

[PHONE_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725262(v=vs.85))