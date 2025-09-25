# ITfLangBarItemMgr::GetItemNum

## Description

Obtains the number of items in the language bar.

## Parameters

### `pulCount` [out]

Pointer to a **ULONG** that receives the number of items in the language bar.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pulCount* is invalid. |