# TdhSetDecodingParameter function

## Description

Sets the value of a decoding parameter.

## Parameters

### `Handle` [in]

Type: **TDH_HANDLE**

A valid decoding handle.

### `TdhContext` [in]

Type: **[PTDH_CONTEXT](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-tdh_context)**

Array of context values. The array must not contain duplicate context types.

## Return value

Type: **ULONG**

Returns ERROR_SUCCESS if successful. Otherwise, this function returns one of the following return codes in addition to others.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters is incorrect. This error is returned if the *Handle* or *TdhContext* parameter is **NULL**. This error is also returned if the **ParameterValue** member of the [TDH_CONTEXT](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-tdh_context) struct pointed to by the *TdhContext* parameter does not exist. |
| **ERROR_NOT_ENOUGH_MEMORY** | Memory allocations failed. |

## See also
[TDH_CONTEXT](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-tdh_context)

[TdhOpenDecodingHandle](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhopendecodinghandle)