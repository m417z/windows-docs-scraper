## Description

The **SendRecvXMLStream** method sends a bidirectional printer communication request and receives the response as [IStream](https://learn.microsoft.com/windows/win32/api/objidl/nn-objidl-istream) objects formatted in accordance with the [Bidirectional Communication Schemas](https://learn.microsoft.com/windows-hardware/drivers/print/bidirectional-communication-schema).

## Parameters

### `pSRequest` [in]

A pointer to the bidi communication request as a stream that complies with one of the [Bidirectional Communication Schemas](https://learn.microsoft.com/windows-hardware/drivers/print/bidirectional-communication-schema).

### `ppSResponse` [out]

A pointer to the printer's response as a stream that complies with one of the [Bidirectional Communication Schemas](https://learn.microsoft.com/windows-hardware/drivers/print/bidirectional-communication-schema).

## Return value

The method returns one of the following values.

| Return code | Description |
|---|---|
| **S_OK** | The operation was successful. |
| **E_HANDLE** | The interface handle is invalid. |
| **None of the above** | The **HRESULT** contains an error code that corresponds to the last error. |

Note that the **HRESULT** may contain a system error code that is defined in [Bidi Error Codes](https://learn.microsoft.com/windows-hardware/drivers/print/bidi-error-codes).

## Remarks

The character encoding of *ppSResponse* is UTF-8. The character encoding of *pSRequest* is either UTF-8 or Unicode with a byte order mark OxFEFF.

## See also

[Bidirectional Communication Interfaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/_print/)

[Bidirectional Communication Schema](https://learn.microsoft.com/windows-hardware/drivers/print/bidirectional-communication-schema)

[IBidiSpl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/bidispl/nn-bidispl-ibidispl2)

[Print Spooler Components](https://learn.microsoft.com/windows-hardware/drivers/print/print-spooler-components)