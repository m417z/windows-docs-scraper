## Description

Contains the dynamically changing connection properties. Version two of this structure introduces a time stamp that can be used to synchronize an auxiliary reference stream initialized with [IApoAuxiliaryInputConfiguration](https://learn.microsoft.com/windows/win32/api/audioenginebaseapo/nn-audioenginebaseapo-iapoauxiliaryinputconfiguration).

## Members

### `property`

A [APO_CONNECTION_PROPERTY](https://learn.microsoft.com/windows/win32/api/audioapotypes/ns-audioapotypes-apo_connection_property) structure containing the version 1 properties.

### `u64QPCTime`

An unsigned 64-bit value representing a [QueryPerformanceCounter](https://learn.microsoft.com/windows/win32/api/profileapi/nf-profileapi-queryperformancecounter) (QPC) time stamp for an audio buffer.

## Remarks
If the **u32Signature** field of the [APO_CONNECTION_PROPERTY](https://learn.microsoft.com/windows/win32/api/audioapotypes/ns-audioapotypes-apo_connection_property) structure passed into [IAudioProcessingObjectRT::APOProcess](https://learn.microsoft.com/windows/win32/api/audioenginebaseapo/nf-audioenginebaseapo-iaudioprocessingobjectrt-apoprocess) is equal to **APO_CONNECTION_PROPERTY_V2_SIGNATURE**, the structure can be safely typecast to a **APO_CONNECTION_PROPERTY_V2**.

This structure was introduced to support acoustic echo cancellation scenarios. For more information, see [IApoAcousticEchoCancellation](https://learn.microsoft.com/windows/win32/api/audioenginebaseapo/nn-audioenginebaseapo-iapoacousticechocancellation).

## See also
[APO_CONNECTION_PROPERTY](https://learn.microsoft.com/windows/win32/api/audioapotypes/ns-audioapotypes-apo_connection_property)
[IApoAcousticEchoCancellation](https://learn.microsoft.com/windows/win32/api/audioenginebaseapo/nn-audioenginebaseapo-iapoacousticechocancellation).
[APOProcess](https://learn.microsoft.com/windows/win32/api/audioenginebaseapo/nf-audioenginebaseapo-iaudioprocessingobjectrt-apoprocess)