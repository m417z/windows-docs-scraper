## Description

The **SendRecvXMLString** method sends a bidirectional printer communication request and receives the response as Unicode strings formatted in accordance with the [Bidirectional Communication Schemas](https://learn.microsoft.com/windows-hardware/drivers/print/bidirectional-communication-schema).

## Parameters

### `bstrRequest` [in]

The bidi communication request as a Unicode string that complies with one of the [Bidirectional Communication Schemas](https://learn.microsoft.com/windows-hardware/drivers/print/bidirectional-communication-schema).

### `pbstrResponse` [out]

A pointer to the printer's response as a Unicode string that complies with one of the [Bidirectional Communication Schemas](https://learn.microsoft.com/windows-hardware/drivers/print/bidirectional-communication-schema).

## Return value

The method returns one of the following values.

| Value | Description |
|---|---|
| **S_OK** | The operation was successful. |
| **E_HANDLE** | The interface handle is invalid. |
| **None of the above** | The **HRESULT** contains an error code that corresponds to the last error. |

The **HRESULT** may contain a system error code that is defined in [Bidi Error Codes](https://learn.microsoft.com/windows-hardware/drivers/print/bidi-error-codes).

## See also

[Bidirectional Communication Interfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/_print/)

[IBidiSpl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/bidispl/nn-bidispl-ibidispl2)

[Print Spooler Components](https://learn.microsoft.com/windows-hardware/drivers/print/print-spooler-components)