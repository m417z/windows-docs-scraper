# ITfContextOwnerServices::OnAttributeChange

## Description

Called by a context owner to generate notifications that a support attribute value changed.

## Parameters

### `rguidAttribute` [in]

Specifies the GUID of the support attribute.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

A support attribute is a read-only property maintained by the context owner. The supported attributes are in the Tsattrs.h header file.

## See also

[ITfContextOwnerServices interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcontextownerservices)