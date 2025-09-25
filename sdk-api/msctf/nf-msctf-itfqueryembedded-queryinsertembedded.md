# ITfQueryEmbedded::QueryInsertEmbedded

## Description

Determines if the active context can accept an embedded object.

## Parameters

### `pguidService` [in]

A GUID that identifies the service associated with the object. This value can be **NULL** if *pFormatEtc* is valid.

### `pFormatEtc` [in]

Pointer to a [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structure that contains data about the object to be embedded. This value can be **NULL** if *pguidService* is valid.

### `pfInsertable` [out]

Pointer to a Boolean value that receives the query result. This value receives a nonzero value if the object can be embedded, or zero otherwise.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **TF_E_DISCONNECTED** | There is no active context. |

## See also

[ITfQueryEmbedded](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfqueryembedded)

[The FORMATETC Structure](https://learn.microsoft.com/windows/desktop/com/the-formatetc-structure)