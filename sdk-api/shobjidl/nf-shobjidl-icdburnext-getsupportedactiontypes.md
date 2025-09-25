# ICDBurnExt::GetSupportedActionTypes

## Description

Determines the supported data type for a CD writing extension.

## Parameters

### `pdwActions` [out]

Type: **CDBE_ACTIONS***

One of the following values indicating the supported type.

#### CDBE_TYPE_MUSIC (0x00000001)

0x00000001. Music files are supported. The CD writing extension is invoked for the **Copy to audio CD** task in the My Music folder.

#### CDBE_TYPE_DATA (0x00000002)

0x00000002. Data files are supported. The CD writing extension is excluded from **Copy to audio CD**.

#### CDBE_TYPE_ALL ((int)0xFFFFFFFF)

(int)0xFFFFFFFF. All files are supported. The CD writing extension is invoked for the **Copy to audio CD** task in the My Music folder.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.