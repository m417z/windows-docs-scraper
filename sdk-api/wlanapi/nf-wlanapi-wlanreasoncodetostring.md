# WlanReasonCodeToString function

## Description

The **WlanReasonCodeToString** function retrieves a string that describes a specified reason code.

## Parameters

### `dwReasonCode` [in]

A [WLAN_REASON_CODE](https://learn.microsoft.com/windows/desktop/NativeWiFi/wlan-reason-code) value of which the string description is requested.

### `dwBufferSize` [in]

The size of the buffer used to store the string, in **WCHAR**. If the reason code string is longer than the buffer, it will be truncated and NULL-terminated. If *dwBufferSize* is larger than the actual amount of memory allocated to *pStringBuffer*, then an access violation will occur in the calling program.

### `pStringBuffer` [in]

Pointer to a buffer that will receive the string. The caller must allocate memory to *pStringBuffer* before calling **WlanReasonCodeToString**.

### `pReserved`

Reserved for future use. Must be set to **NULL**.

## Return value

If the function succeeds, the return value is a pointer to a constant string.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This error is returned if any of the following conditions occur:<br><br>* *dwBufferSize* is 0.<br>* *pStringBuffer* is **NULL**.<br>* *pReserved* is not **NULL**. |
| **Other** | Various RPC and other error codes. Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## See also

[WLAN_REASON_CODE](https://learn.microsoft.com/windows/desktop/NativeWiFi/wlan-reason-code)