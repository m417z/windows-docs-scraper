# IMFMediaEngineClassFactoryEx::CreateMediaKeys

## Description

Creates a media keys object based on the specified key system.

## Parameters

### `keySystem`

The media keys system.

### `cdmStorePath`

Points to a location to store Content Decryption Module (CDM) data which might be locked by multiple process and so might be incompatible with store app suspension.

### `ppKeys`

The media keys.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 Checks if *keySystem* is a supported key system and creates the related Content Decryption Module (CDM).

## See also

[IMFMediaEngineClassFactoryEx](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineclassfactoryex)