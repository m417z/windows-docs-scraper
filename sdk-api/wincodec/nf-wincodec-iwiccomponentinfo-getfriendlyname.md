# IWICComponentInfo::GetFriendlyName

## Description

Retrieves the component's friendly name, which is a human-readable display name for the component.

## Parameters

### `cchFriendlyName` [in]

Type: **UINT**

The size of the *wzFriendlyName* buffer.

### `wzFriendlyName` [in, out]

Type: **WCHAR***

A pointer that receives the friendly name of the component.
The locale of the string depends on the value that the codec wrote to the registry at install time. For built-in components, these strings are always in English.

### `pcchActual` [out]

Type: **UINT***

A pointer that receives the actual length of the component's friendly name.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If *cchFriendlyName* is 0 and *wzFriendlyName* is **NULL**, the required buffer size is returned in *pccchActual*.