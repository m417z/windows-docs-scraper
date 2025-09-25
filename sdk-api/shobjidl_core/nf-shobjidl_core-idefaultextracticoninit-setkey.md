# IDefaultExtractIconInit::SetKey

## Description

Sets the registry key from which to load the "DefaultIcon" value.

## Parameters

### `hkey` [in]

Type: **HKEY**

A handle to the registry key.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

It is recommended that any call to **IDefaultExtractIconInit::SetKey** come before any calls to the SetXxxIcon methods.