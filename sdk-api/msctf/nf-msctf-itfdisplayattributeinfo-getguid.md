# ITfDisplayAttributeInfo::GetGUID

## Description

Obtains the GUID for the display attribute.

## Parameters

### `pguid` [out]

Pointer to a GUID value that receives the GUID for the display attribute.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pguid* is invalid. |

## See also

[ITfDisplayAttributeInfo interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfdisplayattributeinfo)