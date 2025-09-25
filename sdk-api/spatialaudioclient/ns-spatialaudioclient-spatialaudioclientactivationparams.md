# SpatialAudioClientActivationParams structure

## Description

Represents optional activation parameters for a spatial audio render stream. Pass this structure to [ActivateAudioInterfaceAsync](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-activateaudiointerfaceasync) when activating an [ISpatialAudioClient](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioclient) interface.

## Members

### `tracingContextId`

An app-defined context identifier, used for event logging.

### `appId`

An identifier for the client app, used for event logging.

#### majorVersion

The major version number of the client app, used for event logging.

##### minorVersion1

The first minor version number of the client app, used for event logging.

###### minorVersion2

The second minor version number of the client app, used for event logging.

####### minorVersion3

The third minor version number of the client app, used for event logging.

### `majorVersion`

### `minorVersion1`

### `minorVersion2`

### `minorVersion3`

## Remarks

The following example code shows how to initialize this structure.

```cpp
PROPVARIANT var;
PropVariantInit(&var);
auto p = reinterpret_cast<SpatialAudioClientActivationParams *>(CoTaskMemAlloc(sizeof(SpatialAudioClientActivationParams)));
if (nullptr == p) { ... }
p->tracingContextId = /* context identifier */;
p->appId = /* app identifier */;
p->majorVersion = /* app version info */;
p->majorVersionN = /* app version info */;
var.vt = VT_BLOB;
var.blob.cbSize = sizeof(*p);
var.blob.pBlobData = reinterpret_cast<BYTE *>(p);
hr = ActivateAudioInterfaceAsync(device, __uuidof(ISpatialAudioClient), &var, ...);
// ...
ropVariantClear(&var);
```

To access the **ActivateAudioIntefaceAsync**, you will need to link to mmdevapi.lib.