# ITfLangBarItemMgr::EnumItems

## Description

Obtains an enumerator that contains the items in the language bar.

## Parameters

### `ppEnum` [out]

Pointer to an [IEnumTfLangBarItems](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-ienumtflangbaritems) interface pointer that receives the enumerator object.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | *ppEnum* is invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## See also

[IEnumTfLangBarItems](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-ienumtflangbaritems)

[ITfLangBarItemMgr](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritemmgr)