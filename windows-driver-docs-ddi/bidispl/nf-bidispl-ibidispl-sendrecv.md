## Description

The **SendRecv** method sends a bidi request to the printer.

## Parameters

### `pszAction` [in]

A pointer to a NULL-terminated string that specifies the action for this bidi request. It can be one of the following constants.

| Constant | Value | Description |
|---|---|---|
| BIDI_ACTION_ENUM_SCHEMA | L"EnumSchema" | Enumerate the schema. The returned data will be a list of schema that the port monitor or print provider supports. |
| BIDI_ACTION_GET | L"Get" | Get the value of a specified schema. |
| BIDI_ACTION_GET_ALL | L"GetAll" | Get the values of all child nodes of the specified schema. |
| BIDI_ACTION_SET | L"Set" | Set a value of the schema. |
| BIDI_ACTION_GET_WITH_ARGUMENT | L"GetWithArgument" | Request the bidi schema value using the data set as input argument. |

### `pRequest` [in]

A pointer to a single bidi request.

## Return value

The method returns one of the following values.

| Value | Description |
|---|---|
| **S_OK** | The operation was successfully carried out. |
| **E_HANDLE** | The interface handle was invalid. |
| **None of the above** | The **HRESULT** contains an error code corresponding to the last error. |

Note that the **HRESULT** may contain a system error code defined in [Bidi Error Codes](https://learn.microsoft.com/windows-hardware/drivers/print/bidi-error-codes).

## Remarks

The BIDI_ACTION_* values are case insensitive strings.

## See also

[Bidirectional Communication Interfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/_print/)

[Bidirectional Communication Schema](https://learn.microsoft.com/windows-hardware/drivers/print/bidirectional-communication-schema)

[IBidiSpl](https://learn.microsoft.com/windows-hardware/drivers/ddi/bidispl/nn-bidispl-ibidispl)