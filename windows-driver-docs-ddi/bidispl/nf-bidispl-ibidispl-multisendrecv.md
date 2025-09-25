## Description

The **MultiSendRecv** method sends a list of bidi requests.

## Parameters

### `pszAction` [in]

A pointer to a NULL-terminated string that specifies the action for this bidi request. It can be one of the following constants.

| Constant | Value | Description |
|---|---|---|
| BIDI_ACTION_ENUM_SCHEMA | L"EnumSchema" | Enumerate the schema. The returned data will be a list of schema that the port monitor or print provider supports. |
| BIDI_ACTION_GET | L"Get" | Get the value of a specified schema. |
| BIDI_ACTION_GET_ALL | L"GetAll" | Get the values of all child nodes of the specified schema. |
| BIDI_ACTION_SET | L"Set" | Set a value of the schema. |

### `pRequestContainer` [in]

A pointer to the list of bidi requests.

## Return value

The method returns one of the following values. For more information about COM error codes, see [COM Error Codes](https://learn.microsoft.com/windows/win32/com/com-error-codes).

| Value | Description |
|---|---|
| **S_OK** | The operation was successfully carried out. |
| **E_HANDLE** | The interface handle was invalid. |
| **None of the above** | The **HRESULT** contains an error code corresponding to the last error. |

The **HRESULT** may contain a system error code defined in [Bidi Error Codes](https://learn.microsoft.com/windows-hardware/drivers/print/bidi-error-codes).

## Remarks

The BIDI_ACTION_* values are case insensitive strings.

## See also

[Bidirectional Communication Interfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/_print/)

[Bidirectional Communication Schema](https://learn.microsoft.com/windows-hardware/drivers/print/bidirectional-communication-schema)

[IBidiSpl](https://learn.microsoft.com/windows-hardware/drivers/ddi/bidispl/nn-bidispl-ibidispl)