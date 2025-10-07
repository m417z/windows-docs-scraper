# MpErrorMessageFormat function

Returns a formatted error message based on an error code.

## Parameters

*hMpHandle* \[in\]

Type: **MPHANDLE**

Handle to the malware protection manager interface. This handle is returned by the [**MpManagerOpen**](https://learn.microsoft.com/windows/win32/lwef/mpmanageropen) function.

*hrError* \[in\]

Type: **HRESULT**

An **HRESULT**-based error code.

*pwszErrorDesc* \[out\]

Type: **LPWSTR\***

Returns a formatted error message based on *hrError*. This string must be freed using [**MpFreeMemory**](https://learn.microsoft.com/windows/win32/lwef/mpfreememory).

## Return value

Type: **HRESULT**

If the function succeeds the return value is **S\_OK**.

If the function fails then the return value is a failed **HRESULT** code.

## Remarks

This function is capable of formatting system error codes in addition to specific error codes returned by malware protection functions. The **HRESULT** error codes specific to malware protection functions have a facility of 0x50. Below is a list of a subset of the malware protection-specific error codes that can be returned by various malware protection functions. Using the macro **HRESULT\_FROM\_MP\_STATUS**, the following error codes can be converted to **HRESULT**. See also [Forefront Client Security anti-malware engine error codes](https://support.microsoft.com/kb/939359) for a list of other possible error codes.

| Error Code | Description |
|-----------------------------------------|-----------------------------------------------------------------------------------------------------------------------------|
| ERROR\_MP\_NOENGINE | No engine is loaded in antimalware service to perform the requested operation. |
| ERROR\_MP\_NO\_MEMORY | The antimalware engine has encountered a no memory situation. |
| ERROR\_MP\_REMOVE\_FAILED | Remove operation failed for a specific threat. |
| ERROR\_MP\_QUARANTINE\_FAILED | Quarantine operation failed for a specific threat. |
| ERROR\_MP\_THREAT\_NOT\_FOUND | The specific threat no longer exists in the system. |
| ERROR\_MP\_REMOVE\_NOT\_SUPPORTED | Remove operation for a specific threat inside the container type is not supported. |
| ERROR\_MP\_REMOVE\_IMMUTABLE\_CONTAINER | Due to engine policy, a remove operation of a specific threat inside a blocked container is not supported. (Mail archives.) |
| ERROR\_MP\_BADDB\_OLDENGINE | Signature update request provided an older engine or signature files(s). |

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | MpClient.h |
| DLL<br> | MpClient.dll |

## See also

[**MpFreeMemory**](https://learn.microsoft.com/windows/win32/lwef/mpfreememory)

[**MpManagerOpen**](https://learn.microsoft.com/windows/win32/lwef/mpmanageropen)

[Forefront Client Security anti-malware engine error codes](https://support.microsoft.com/kb/939359)

