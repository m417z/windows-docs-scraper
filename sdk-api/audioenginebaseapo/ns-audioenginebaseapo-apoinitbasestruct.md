# APOInitBaseStruct structure

## Description

The APOInitBaseStruct structure is the base initialization header that must precede other
initialization data in [IAudioProcessingObject::Initialize](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/nf-audioenginebaseapo-iaudioprocessingobject-initialize).

## Members

### `cbSize`

The total size of the structure in bytes.

### `clsid`

The Class ID (CLSID) of the APO.

## Remarks

If the specified CLSID does not match, then the APOInitBaseStruct structure was not designed for this APO, and this is an error condition. And if the CLSID of the APO changes
between versions, then the CLSID may also be used for version management. In the case where the CLSID is used for version management, a previous version may still be supported by the APO.

## See also

[APOInitSystemEffects](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/ns-audioenginebaseapo-apoinitsystemeffects)

[IAudioProcessingObject::Initialize](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/nf-audioenginebaseapo-iaudioprocessingobject-initialize)