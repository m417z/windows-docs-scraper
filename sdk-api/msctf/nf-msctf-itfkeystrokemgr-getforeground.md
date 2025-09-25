# ITfKeystrokeMgr::GetForeground

## Description

Obtains the class identifier of the foreground TSF text service.

## Parameters

### `pclsid` [out]

Pointer to a CLSID that receives the class identifier of the foreground TSF text service.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | There is no foreground text service. |
| **E_INVALIDARG** | *pclsid* is invalid. |
| **E_FAIL** | An unspecified error occurred. |