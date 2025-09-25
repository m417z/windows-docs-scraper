# GetIScsiSessionListA function

## Description

The **GetIscsiSessionList** function retrieves the list of active iSCSI sessions.

## Parameters

### `BufferSize` [in, out]

A pointer to a location that, on input, contains the size, in bytes, of the caller-allocated buffer that *SessionInfo* points to. If the operation succeeds, the location receives the size, in bytes, of the session information data that was retrieved.

If the operation fails because the output buffer size was insufficient, the location receives the size, in bytes, of the buffer size required to contain the output data.

### `SessionCount` [out]

A pointer to a location that, on input, contains the number of [ISCSI_SESSION_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_session_infoa) structures that the buffer that *SessionInfo* points to can contain. If the operation succeeds, the location receives the number of **ISCSI_SESSION_INFO** structures that were retrieved.

### `SessionInfo` [out]

A pointer to a buffer that contains a series of contiguous structures of type [ISCSI_SESSION_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_session_infoa) that describe the active login sessions.

## Return value

Returns ERROR_SUCCESS if the operation succeeds and ERROR_INSUFFICIENT_BUFFER if the size of the buffer at *SessionInfo* was insufficient to hold the output data.

Otherwise, **GetIscsiSessionList** returns the appropriate Win32 or iSCSI error code on failure.

## See also

[ISCSI_SESSION_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_session_infoa)

## Remarks

> [!NOTE]
> The iscsidsc.h header defines GetIScsiSessionList as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).