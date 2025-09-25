# IMarshalingStream::GetMarshalingContextAttribute

## Description

Gets information about the marshaling context.

## Parameters

### `attribute` [in]

The attribute to query.

### `pAttributeValue` [out]

The value of *attribute*.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Each possible value of the attribute parameter is paired with the data type of the attribute this identifies.

You can query the following attributes with this method.

| Attribute | Values |
| --- | --- |
| CO_MARSHALING_SOURCE_IS_APP_CONTAINER | This attribute is a boolean value, with 0 representing **TRUE** and nonzero representing **FALSE**. You can safely cast the value of the result to **BOOL**, but it isn't safe for the caller to cast a **BOOL*** to **ULONG_PTR*** for the *pAttributeValue* parameter, or for the implementation to cast *pAttributeValue* to **BOOL*** when setting it. |

## See also

[CO_MARSHALING_CONTEXT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-co_marshaling_context_attributes)

[IGlobalOptions](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iglobaloptions)

[IMarshalingStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshalingstream)