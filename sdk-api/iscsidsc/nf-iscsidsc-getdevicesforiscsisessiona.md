# GetDevicesForIScsiSessionA function

## Description

The **GetDevicesForIscsiSession** function retrieves information about the devices associated with the current session.

## Parameters

### `UniqueSessionId` [in]

A pointer to a structure of type [ISCSI_UNIQUE_SESSION_ID](https://learn.microsoft.com/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_unique_session_id) that contains the session identifier for the session.

### `DeviceCount` [in, out]

A pointer to a location that, on input, contains the number of elements of type [ISCSI_DEVICE_ON_SESSION](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_device_on_sessiona) that can fit in the buffer that *Devices* points to. If the operation succeeds, the location receives the number of elements retrieved. If **GetDevicesForIscsiSession** returns ERROR_INSUFFICIENT_BUFFER, the location still receives the number of elements the buffer is capable of containing.

### `Devices` [out]

An array of [ISCSI_DEVICE_ON_SESSION](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_device_on_sessiona)-type structures that, on output, receives information about each device associated with the session.

## Return value

Returns ERROR_SUCCESS if the operation succeeds and ERROR_INSUFFICIENT_BUFFER if the caller allocated insufficient buffer space for the array in Devices.

Otherwise, **GetDevicesForIscsiSession** returns the appropriate Win32 or iSCSI error code on failure.

## See also

[ISCSI_DEVICE_ON_SESSION](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_device_on_sessiona)

[ISCSI_UNIQUE_SESSION_ID](https://learn.microsoft.com/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_unique_session_id)

## Remarks

> [!NOTE]
> The iscsidsc.h header defines GetDevicesForIScsiSession as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).