## Description

Returns the implementation of [IMFContentDecryptionModuleFactory](https://learn.microsoft.com/windows/win32/api/mfcontentdecryptionmodule/nn-mfcontentdecryptionmodule-imfcontentdecryptionmodulefactory) for the specified key system that is built-in to Windows.

## Parameters

### `keySystem` [in]

A PCWSTR identifying the key system for which the decryption module is returned.

### `contentDecryptionModuleFactory` [out]

If the specified key system is found, receives pointer to an **IMFContentDecryptionModuleFactory** implementation; otherwise, NULL.

## Return value

An HRESULT including the following values:

| Value | Description |
|-------|-------------|
| S_OK | Success. This function returns success even if the specified key system is not found, but in this case, the *contentDecryptionModuleFactory* parameter is NULL. |
| CO_E_NOTINITIALIZED | COM was not initialized before the function was called |

## Remarks

**GetDefaultContentDescryptionModuleFactory** only considers content decryption module factories that are built-in to Windows and does not consider content decryption module factories that have been downloaded from the Microsoft Store.

It is recommended that apps use [IMFMediaEngineClassFactory4::CreateContentDecryptionModuleFactory](https://learn.microsoft.com/windows/win32/api/windows/win32/api/mfmediaengine/nf-mfmediaengine-imfmediaengineclassfactory4-createcontentdecryptionmodulefactory), as this method first calls **GetDefaultContentDecryptionModuleFactory** , but then also searches for any matching implementations of **IMFContentDecryptionModuleFactory** that may have been downloaded from the Microsoft Store.

## See also