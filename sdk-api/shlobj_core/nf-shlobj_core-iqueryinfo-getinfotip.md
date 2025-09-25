# IQueryInfo::GetInfoTip

## Description

Gets the info tip text for an item.

## Parameters

### `dwFlags`

Type: **DWORD**

Flags that direct the handling of the item from which you're retrieving the info tip text. This value is commonly zero (**QITIPF_DEFAULT**). The following values are recognized.

#### QITIPF_DEFAULT (0x00000000)

No special handling.

#### QITIPF_USENAME (0x00000001)

Provide the name of the item in *ppwszTip* rather than the info tip text.

#### QITIPF_LINKNOTARGET (0x00000002)

If the item is a shortcut, retrieve the info tip text of the shortcut rather than its target.

#### QITIPF_LINKUSETARGET (0x00000004)

If the item is a shortcut, retrieve the info tip text of the shortcut's target.

#### QITIPF_USESLOWTIP (0x00000008)

Search the entire namespace for the information. This value can result in a delayed response time.

#### QITIPF_SINGLELINE (0x00000010)

**Windows Vista and later**. Put the info tip on a single line.

### `ppwszTip` [out]

Type: **PWSTR***

The address of a Unicode string pointer that, when this method returns successfully, receives the tip string pointer. Applications that implement this method must allocate memory for *ppwszTip* by calling [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc). Calling applications must call [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to free the memory when it is no longer needed.

## Return value

Type: **HRESULT**

Returns S_OK if the function succeeds. If no info tip text is available, *ppwszTip* is set to **NULL**. Otherwise, returns a COM-defined error value.

## See also

[IQueryInfo](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iqueryinfo)