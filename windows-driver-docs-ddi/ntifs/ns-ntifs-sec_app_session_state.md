## Description

The **SEC_APP_SESSION_STATE** structure is used to store and manage application-specific session state information. This structure is typically associated with session tickets to maintain state across secure sessions.

## Members

### `AppSessionStateSize`

Size, in bytes, of the application state data contained in the **AppSessionState** array. The maximum size allowed is 2048 bytes.

### `AppSessionState[ANYSIZE_ARRAY]`

An array of bytes representing the application-specific state data to be associated with the session ticket. This array is flexible in size, allowing it to accommodate varying amounts of state information.