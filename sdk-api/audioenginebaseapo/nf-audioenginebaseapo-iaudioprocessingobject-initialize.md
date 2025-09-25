# IAudioProcessingObject::Initialize

## Description

The Initialize method initializes the APO and supports data of variable length.

## Parameters

### `cbDataSize` [in]

This is the size, in bytes, of the initialization data.

### `pbyData` [in]

This is initialization data that is specific to this APO.

## Return value

The `Initialize` method returns a value of S_OK if the call was successful. Otherwise, this method returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Invalid pointer passed to the function. |
| **E_INVALIDARG** | Invalid argument. |
| **APOERR_ALREADY_INITIALIZED** | APO already initialized. |
| **Other HRESULTS** | These additional error conditions are tracked by the audio engine. |

## Remarks

If this method is used to initialize an APO without the need to initialize any data, it is acceptable to supply a **NULL** as the value of the pbyData parameter and a 0 (zero) as the value of the cbDataSize parameter. The data that is supplied is of variable length and must have the following format:

```
Struct MyAPOInitializationData
{
APOInitBaseStruct APOInit;
// list additional struct members here
// ...
};
```

## See also

[APOInitBaseStruct](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/ns-audioenginebaseapo-apoinitbasestruct)