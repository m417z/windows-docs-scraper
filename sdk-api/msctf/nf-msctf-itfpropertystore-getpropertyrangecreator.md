# ITfPropertyStore::GetPropertyRangeCreator

## Description

Obtains the class identifier of the property store owner.

## Parameters

### `pclsid` [out]

Pointer to a **CLSID** that receives the class identifier of the registered text service that implements [ITfCreatePropertyStore](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcreatepropertystore). The method can return CLSID_NULL for this parameter if property store persistence is unsupported.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

When the property store is unserialized, the TSF manager creates an object of this CLSID and obtains an **ITfCreatePropertyStore** interface pointer from it. The manager then uses the **ITfCreatePropertyStore** object to create the property store object.

## See also

[ITfCreatePropertyStore](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcreatepropertystore)

[ITfPropertyStore](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfpropertystore)