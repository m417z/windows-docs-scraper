# ITfContextOwner::GetAttribute

## Description

The **ITfContextOwner::GetAttribute** method returns the value of a supported attribute. If the attribute is unsupported, the *pvarValue* parameter is set to VT_EMPTY.

## Parameters

### `rguidAttribute` [in]

Specifies the attribute GUID.

### `pvarValue` [out]

Receives the attribute value. If the attribute is unsupported, this parameter is set to VT_EMPTY.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

Context owners using the default text store of the TSF manager can implement a simplified version of attributes with this method. The supported attributes are application or text service dependent. For more information about predefined attributes recognized in TSF, see the following topics.

## See also

[ITfContextOwner](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontextowner)

[Other Predefined Attributes](https://learn.microsoft.com/windows/desktop/TSF/other-predefined-attributes)

[Predefined Font Attributes](https://learn.microsoft.com/windows/desktop/TSF/predefined-font-attributes)

[Predefined List Attributes](https://learn.microsoft.com/windows/desktop/TSF/predefined-list-attributes)

[Predefined Text Attributes](https://learn.microsoft.com/windows/desktop/TSF/predefined-text-attributes)