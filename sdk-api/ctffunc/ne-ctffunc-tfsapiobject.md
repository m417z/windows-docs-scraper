# TfSapiObject enumeration

## Description

Elements of the **TfSapiObject** enumeration are used with the [ITfFnGetSAPIObject::Get](https://learn.microsoft.com/windows/desktop/api/ctffunc/nf-ctffunc-itffngetsapiobject-get) method to specify a specific type of Speech API (SAPI) object.

## Constants

### `GETIF_RESMGR:0`

Specifies an ISpResourceManager object.

### `GETIF_RECOCONTEXT:0x1`

Specifies an ISpRecoContext object.

### `GETIF_RECOGNIZER:0x2`

Specifies an ISpRecognizer object.

### `GETIF_VOICE:0x3`

Specifies an ISpVoice object.

### `GETIF_DICTGRAM:0x4`

Specifies an ISpRecoGrammar object.

### `GETIF_RECOGNIZERNOINIT:0x5`

Specifies an ISpRecognizer object. SAPI will not be initialized if it is not already.

## See also

[ITfFnGetSAPIObject::Get](https://learn.microsoft.com/windows/desktop/api/ctffunc/nf-ctffunc-itffngetsapiobject-get)