# IMFMediaEngineClassFactory2::CreateMediaKeys2

## Description

Creates a media keys object based on the specified key system.

## Parameters

### `keySystem` [in]

The media key system.

### `defaultCdmStorePath` [in]

Points to the default file location for the store Content Decryption Module (CDM) data.

### `inprivateCdmStorePath` [in, optional]

Points to a the inprivate location for the store Content Decryption Module (CDM) data. Specifying this path allows the CDM to comply with the application’s privacy policy by putting personal information in the file location indicated by this path.

### `ppKeys` [out]

Receives the media keys.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFMediaEngineClassFactory2](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineclassfactory2)

[IMFMediaKeys](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediakeys)